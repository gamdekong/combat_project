#include "Lobby.h"
#include "SimpleAudioEngine.h"


#define PLAYER_SWORD "sounds/player/player_sword.ogg"
#define PLAYER_HITTED "sounds/player/player_hitted.ogg"
#define CLICK "sounds/click/click.ogg"
#define INTRO_BGM "sounds/intro/intro_bgm.ogg"
#define LOBBY_BGM "sounds/lobby/lobby_bgm.ogg"
#define STAGE1_BGM "sounds/stage1/stage1_bgm.ogg"
#define STAGE2_BGM "sounds/stage2/stage2_bgm.ogg"
#define STAGE3_BGM "sounds/stage3/stage3_bgm.ogg"
#define ITEM_GET "sounds/item/item_get.ogg"
#define ITEM_USE "sounds/item/item_use.ogg"

using namespace CocosDenshion;
USING_NS_CC;

Scene* Lobby::createScene()
{

	auto scene = Scene::create();
	auto layer = Lobby::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Lobby::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	
	//missileBodyVector.clear();
	//monsterBodyVector.clear();
	winSize = Director::getInstance()->getWinSize();

	player = new Player();
	this->addChild(player, 1);
	//player->setOpacity(256);
	
	
	firegirl = new Monster(9);
	firegirl->setPosition(Vec2(450, 400));
	firegirl->setFlippedX(true);
	this->addChild(firegirl,1);

	auto fire = new Monster(11);
	fire->setPosition(Vec2(400, 370));
	this->addChild(fire, 1);

	



	// 월드 생성

	if (this->createWorld(false))
	{
		this->schedule(schedule_selector(Lobby::tick));
		myContactListener = new ContactListener(player);

		_world->SetContactListener((b2ContactListener*)myContactListener);
	}

	this->createPlayer(player);  //바디 생성
	this->createMonster(firegirl);
	this->createMonster(fire);
	

	this->createBackground();   //배경 이미지 생성
	this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동

	auto clickSprite = Sprite::create("menu/click.png");
	clickSprite->setPosition(Vec2(firegirl->getContentSize().width+80, firegirl->getContentSize().height+20));
	auto seq = Sequence::create(FadeOut::create(0.2), FadeIn::create(0.2), nullptr);
	auto seqR = RepeatForever::create(seq);

	
	firegirl->addChild(clickSprite);
	clickSprite->runAction(seqR);
	return true;
}

bool Lobby::createWorld(bool debug)
{
	//월드 생성 시작

	b2Vec2 gravity = b2Vec2(0.0f, .0f);

	//월드를 생성한다.
	_world = new b2World(gravity);

	//휴식 상태일 때 포함된 바디들을 멈추게(sleep)할 것인지 결정한다
	_world->SetAllowSleeping(true);

	//지속적인 물리작용을 할 것인지 결정한다. :테스트
	_world->SetContinuousPhysics(true);


	if (debug)
	{
		//적색 : 현재 물리 운동을 하는 것
		//회색 : 현재 물리 운동량이 없는 것
		m_debugDraw = new GLESDebugDraw(PTM_RATIO);
		_world->SetDebugDraw(m_debugDraw);

		uint32 flags = 0;

		flags += b2Draw::e_shapeBit;

		m_debugDraw->SetFlags(flags);
	}




	//가장자리(테두리)를 지정해 공간(Ground Box)을 만든다.

	//바디데프에 좌표를 설정한다.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);

	//월드에 바디데프의 정보(좌표)로 바디를 만든다.
	b2Body *groundBody = _world->CreateBody(&groundBodyDef);

	//가장 자리(테두리) 경계선을 그릴수 있는 모양의 객체를 만든다.

	b2EdgeShape groundEdge;
	b2FixtureDef boxShapeDef;
	boxShapeDef.shape = &groundEdge;
	boxShapeDef.filter.categoryBits = CATEGORY_GROUND;
	boxShapeDef.filter.maskBits = CATEGORY_MONSTER + CATEGORY_PLAYER;

	//에지 모양의 객체에 Set(점1, 점2)선을 만든다.
	//그리고 바디(groundBody)에 모양(groundEdge)을 고정시킨다.

	//왼쪽 기운쪽
	groundEdge.Set(b2Vec2(0, 240 / PTM_RATIO), b2Vec2(200 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//왼쪽
	groundEdge.Set(b2Vec2(0, 100 / PTM_RATIO), b2Vec2(0, 240 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//아래쪽
	groundEdge.Set(b2Vec2(0, 100 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 100 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//위쪽1
	groundEdge.Set(b2Vec2(200 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1000 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//위쪽3
	groundEdge.Set(b2Vec2(1100 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1300 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//오른쪽 기운쪽
	groundEdge.Set(b2Vec2(1300 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 240 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//오른쪽
	groundEdge.Set(b2Vec2(1500 / PTM_RATIO, 240 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 100 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//월드 생성 끝-----------------------



	return true;
}


void Lobby::tick(float dt)
{
	//물리적 위치를 이용해 그래픽 위치는 갱신한다.

	//velocityIterations : 바디들을 정상적으로 이동시키기 위해 필요한 충돌들을
	//반복적으로 계산
	//positionIterations : 조인트 분리와 겹침 현상을 줄이기 위해 바디의 위치를
	//반복적으로 적용
	//값이 클수록 정확한 연산이 가능하지만 성능이 떨어진다.

	//메뉴얼 상의 권장값
	int velocityIterations = 8;
	int positionIterations = 3;

	//Step : 물리 세계를 시뮬레이션한다.
	_world->Step(dt, velocityIterations, positionIterations);
	//모든 물리 객체들은 링크드 리스트에 저장되어 참조해 볼수 있게 구현돼 있다.
	//만들어진 객체만큼 루프를 돌리면서 바디에 붙인 스프라이트를 여기서 제어한다.
	for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			Sprite *spriteData = (Sprite*)b->GetUserData();
			spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO));
			spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));

			if (b->GetUserData() == player)
			{
				float vx = joystickVelocity1->x * player->speed;//스피드
				float vy = joystickVelocity1->y * player->speed;
				//set ball velocity by Joystick
				b->SetLinearVelocity(b2Vec2(vx, vy) + (b->GetLinearVelocity()));

			}


		}


	}


	//미사일 바디 삭제와 벡터에서의 바디 삭제
	for (int i = 0; i < missileBodyVector.size(); i++)
	{

		if (missileBodyVector[i]->GetUserData() == nullptr)
		{
			_world->DestroyBody(missileBodyVector[i]);
			missileBodyVector.erase(missileBodyVector.begin() + i);
			//log("%d", missileBodyVector.size());
		}
		//if (missileBodyVector.size() > 0)

		//log("%d", missileBodyVector.size());

	}



	if (joystickVelocity2->x > 0.9)
	{
		LongAttack(RIGHTLONGATTACK);

	}
	else if (joystickVelocity2->x < -0.9)
	{
		LongAttack(LEFTLONGATTACK);
	}





	// 캐릭터 이동 관련 부분
	if (joystickVelocity1->x == 0 && joystickVelocity1->y == 0 && isMoving == false)
	{

		player->stopAllActions();
		player->IdleAction();
		isMoving = true;

	}
	else if (joystickVelocity1->x < 0)
	{
		//log("%f", joystick1->getVelocity().x);
		if (isMoving == true)
		{
			player->stopAllActions();
			player->MoveAction();
			isMoving = false;
		}
		player->setFlippedX(true);

	}
	else if (joystickVelocity1->x > 0)
	{
		//log("%f", joystick1->getVelocity().x);
		if (isMoving == true)
		{
			player->stopAllActions();
			player->MoveAction();
			isMoving = false;
		}
		player->setFlippedX(false);

	}


	for (int i = 0; i < monsterBodyVector.size(); i++)
	{

		Monster *monster = (Monster*)(monsterBodyVector[i]->GetUserData());

		//  충돌 처리
		if (player->getPosition().y < monster->getPosition().y + 30 && player->getPosition().y > monster->getPosition().y - 30)
		{
			//log("dddd");
			auto newFilter = new b2Filter();
			auto oldFilter = new b2Filter();
			*oldFilter = monsterBodyVector[i]->GetFixtureList()->GetFilterData();
			newFilter = oldFilter;
			newFilter->maskBits = CATEGORY_PLAYER;
			monsterBodyVector[i]->GetFixtureList()->SetFilterData(*newFilter);
		}
		else
		{
			auto newFilter = new b2Filter();
			auto oldFilter = new b2Filter();
			*oldFilter = monsterBodyVector[i]->GetFixtureList()->GetFilterData();
			newFilter = oldFilter;
			newFilter->maskBits = 200;
			monsterBodyVector[i]->GetFixtureList()->SetFilterData(*newFilter);

		}

		// ZOrder 처리
		if (player->getPosition().y > monster->getPosition().y + 30)
			player->setZOrder(monster->getZOrder() - 1);
		else if (player->getPosition().y < monster->getPosition().y + 30)
			player->setZOrder(monster->getZOrder() + 1);



	}







	if (player->getPosition().x > 1000 && player->getPosition().x < 1100 && player->getPosition().y > 500 && tCount == 0)
	{
		tCount++;
		auto pScene = Stage1_Layer::createScene();
	
		Director::getInstance()->replaceScene(TransitionFade::create(0.1, pScene));
	}





}


void Lobby::createBackground()
{
	auto bg2 = Sprite::create("lobby/lobbybg.png");
	bg2->setPosition(Vec2(0, 400));
	bg2->setAnchorPoint(Vec2(0, 0));
	this->addChild(bg2,0);

	auto bg = Sprite::create("stage/lobby.png");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 100));
	this->addChild(bg, 0);



	auto door = Sprite::create("structure/door2.png");
	door->setAnchorPoint(Vec2(0, 0));
	door->setPosition(Vec2(965, 398));
	this->addChild(door,0);

	
	
}


void Lobby::draw(Renderer * renderer, const Mat4 & transform, uint32_t flags)
{
	//Layer::draw();
	Layer::draw(renderer, transform, flags);
	GL:ccGLEnableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION);

	kmGLPushMatrix();
	_world->DrawDebugData();
	kmGLPopMatrix();


}

void Lobby::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToNodeSpace(touchPoint);

	bool bTouch = firegirl->getBoundingBox().containsPoint(touchPoint);
	if (bTouch)
	{
		auto readme = Sprite::create("menu/readme.png");
		readme->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
		readme->setScale(1.5);
		readme->setTag(10);
		this->addChild(readme, 5);
		log("firegirl touch..");
	}
	else
		this->removeChildByTag(10);
}

void Lobby::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Lobby::onTouchesBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Lobby::createPlayer(Sprite * player)
{

	//--------------플레이어 바디생성
	b2BodyDef playerBodyDef;
	playerBodyDef.type = b2_dynamicBody;
	playerBodyDef.position.Set(player->getPosition().x / PTM_RATIO, player->getPosition().y / PTM_RATIO);
	playerBodyDef.linearDamping = 20;
	playerBodyDef.userData = player;


	playerBody = _world->CreateBody(&playerBodyDef);

	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);

	b2PolygonShape playerPolygon;
	playerPolygon.SetAsBox((player->getContentSize().width / 6) / PTM_RATIO, (player->getContentSize().height / 2) / PTM_RATIO);
	log(" %f ", (player->getContentSize().height / 2.5));

	b2FixtureDef playerFixtureDef;
	playerFixtureDef.shape = &playerPolygon;
	playerFixtureDef.density = 0.0f;
	playerFixtureDef.filter.groupIndex = GROUP_INDEX_PLAYER;
	playerFixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	playerFixtureDef.filter.maskBits = CATEGORY_MONSTER;
	playerBody->CreateFixture(&playerFixtureDef);

}

void Lobby::createMonster(Sprite * monster)
{
	//--------------플레이어 바디생성
	b2BodyDef monsterBodyDef;
	monsterBodyDef.type = b2_kinematicBody;
	monsterBodyDef.position.Set(monster->getPosition().x / PTM_RATIO, monster->getPosition().y / PTM_RATIO);
	monsterBodyDef.linearDamping = 20;
	monsterBodyDef.userData = monster;


	auto monsterBody = _world->CreateBody(&monsterBodyDef);

	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);

	b2PolygonShape monsterPolygon;
	monsterPolygon.SetAsBox((monster->getContentSize().width / 3) / PTM_RATIO, (monster->getContentSize().height /2 ) / PTM_RATIO);
	//log(" %f ", (monster->getContentSize().height / 2.5));

	b2FixtureDef monsterFixtureDef;
	monsterFixtureDef.shape = &monsterPolygon;
	monsterFixtureDef.density = 0.0f;
	monsterFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	monsterFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	monsterFixtureDef.filter.maskBits = CATEGORY_PLAYER;

	monsterBody->CreateFixture(&monsterFixtureDef);
	monsterBodyVector.push_back(monsterBody);
	auto mon = (Monster*)monster;
	mon->IdleAction();
}

void Lobby::LongAttack(int num)
{
	switch (num)
	{
	case RIGHTLONGATTACK:

		if (!this->isScheduled(schedule_selector(Lobby::RightLongAttack)) &&
			!this->isScheduled(schedule_selector(Lobby::clearTime)))
		{
			this->RightLongAttack(0);
		}
		else if (!this->isScheduled(schedule_selector(Lobby::RightLongAttack)))
			this->scheduleOnce(schedule_selector(Lobby::RightLongAttack), player->attackSpeed);
		break;


	case LEFTLONGATTACK:
		if (!this->isScheduled(schedule_selector(Lobby::LeftLongAttack)) &&
			!this->isScheduled(schedule_selector(Lobby::clearTime)))
		{
			this->LeftLongAttack(0);
		}
		else if (!this->isScheduled(schedule_selector(Lobby::LeftLongAttack)))
			this->scheduleOnce(schedule_selector(Lobby::LeftLongAttack), player->attackSpeed);
		break;
	}
}

void Lobby::RightLongAttack(float dt)
{
	SimpleAudioEngine::getInstance()->playEffect(PLAYER_SWORD);
	SwordMissile *missile = new SwordMissile(1);
	missile->setPosition(Vec2(player->getPosition().x + 50.f, player->getPosition().y));
	missile->setFlipX(true);
	missile->setAnchorPoint(Vec2(0.8, 0.5));
	this->addChild(missile);
	player->stopAllActions();
	player->setFlippedX(false);
	player->AttackAction(isMoving);
	missile->startAction(missile->missileNum);
	//auto move = MoveBy::create(1.75f, Vec2(1500, 0));
	//missile->runAction(move);

	b2BodyDef missileBodyDef;
	missileBodyDef.type = b2_dynamicBody;
	missileBodyDef.position.Set((missile->getPosition().x) / PTM_RATIO, missile->getPosition().y / PTM_RATIO);
	missileBodyDef.linearDamping = 0;
	missileBodyDef.userData = missile;

	auto missileBody = _world->CreateBody(&missileBodyDef);
	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);
	b2PolygonShape missilePolygon;
	missilePolygon.SetAsBox((missile->getContentSize().width / 30) / PTM_RATIO, (missile->getContentSize().height / 3) / PTM_RATIO);

	b2FixtureDef missileFixtureDef;
	missileFixtureDef.shape = &missilePolygon;
	missileFixtureDef.density = 0.0f;
	missileFixtureDef.restitution = 0.5;
	missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	//monsterFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	//monsterFixtureDef.filter.maskBits = CATEGORY_PLAYER;
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(10, 0));
	missileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
	this->scheduleOnce(schedule_selector(Lobby::clearTime), player->attackSpeed);

}
void Lobby::LeftLongAttack(float dt)
{
	SimpleAudioEngine::getInstance()->playEffect(PLAYER_SWORD);
	SwordMissile *missile = new SwordMissile(1);
	missile->setPosition(Vec2(player->getPosition().x - 50.f, player->getPosition().y));
	this->addChild(missile);
	player->stopAllActions();
	player->setFlippedX(true);
	missile->setAnchorPoint(Vec2(0.2, 0.5));
	player->AttackAction(isMoving);
	missile->startAction(missile->missileNum);


	//auto move = MoveBy::create(1.75f, Vec2(1500, 0));
	//missile->runAction(move);

	b2BodyDef missileBodyDef;
	missileBodyDef.type = b2_dynamicBody;
	missileBodyDef.position.Set(missile->getPosition().x / PTM_RATIO, missile->getPosition().y / PTM_RATIO);
	missileBodyDef.linearDamping = 0;
	missileBodyDef.userData = missile;

	auto missileBody = _world->CreateBody(&missileBodyDef);
	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);
	b2PolygonShape missilePolygon;
	missilePolygon.SetAsBox((missile->getContentSize().width / 30) / PTM_RATIO, (missile->getContentSize().height / 3) / PTM_RATIO);

	b2FixtureDef missileFixtureDef;
	missileFixtureDef.shape = &missilePolygon;
	missileFixtureDef.density = 0.0f;
	missileFixtureDef.restitution = 0.5;
	missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	//monsterFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	//monsterFixtureDef.filter.maskBits = CATEGORY_PLAYER;
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(-10, 0));
	missileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
	this->scheduleOnce(schedule_selector(Lobby::clearTime), player->attackSpeed);

}

void Lobby::clearTime(float dt)
{
}

