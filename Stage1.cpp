#include "Stage1.h"

USING_NS_CC;

Scene* Stage1::createScene()
{

	auto scene = Scene::create();
	auto layer = Stage1::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Stage1::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	missileBodyVector.clear();
	monsterBodyVector.clear();
	auto winsize = Director::getInstance()->getWinSize();

	//player = new Player();
	//this->addChild(player, 1);

	if (stageNum == 0)
	{

		auto monster1 = new Monster(1);
		monster1->setPosition(Vec2(500, 200));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(2);
		monster2->setPosition(Vec2(800, 300));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(3);
		monster3->setPosition(Vec2(1000, 300));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(5);
		monster5->setPosition(Vec2(1300, 300));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		  //바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동
		
		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(250, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		//auto brokenTree1 = Sprite::create("structure/Broken_tree_01.png");
		//brokenTree1->setPosition(Vec2(500, 300));
		//this->addChild(brokenTree1);


		initComplete = true;
		log("init %d",stageNum);

	}
	else if (stageNum == 1)
	{

		auto monster1 = new Monster(1);
		monster1->setPosition(Vec2(500, 200));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(4);
		monster2->setPosition(Vec2(800, 300));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(3);
		monster3->setPosition(Vec2(1000, 300));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(6);
		monster5->setPosition(Vec2( 700, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

	  //바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(350, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 2)
	{

		auto monster1 = new Monster(4);
		monster1->setPosition(Vec2(300, 200));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(5);
		monster2->setPosition(Vec2(800, 350));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(8);
		monster3->setPosition(Vec2(1000, 300));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(2);
		monster5->setPosition(Vec2(1000, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(550, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 3)
	{

		auto monster1 = new Monster(2);
		monster1->setPosition(Vec2(600, 300));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(4);
		monster2->setPosition(Vec2(700, 250));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(6);
		monster3->setPosition(Vec2(1000, 300));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(8);
		monster5->setPosition(Vec2(300, 300));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동


		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(650, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 4)
	{

		auto monster1 = new Monster(3);
		monster1->setPosition(Vec2(600, 200));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(6);
		monster2->setPosition(Vec2(800, 300));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(1);
		monster3->setPosition(Vec2(500, 250));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(5);
		monster5->setPosition(Vec2(470, 290));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동


		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(750, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 5)
	{

		auto monster1 = new Monster(1);
		monster1->setPosition(Vec2(300, 300));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(5);
		monster2->setPosition(Vec2(900, 265));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(2);
		monster3->setPosition(Vec2(700, 285));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(8);
		monster5->setPosition(Vec2(100, 250));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(850, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 6)
	{

		auto monster1 = new Monster(8);
		monster1->setPosition(Vec2(400, 350));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(6);
		monster2->setPosition(Vec2(700, 270));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(2);
		monster3->setPosition(Vec2(1000, 270));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(4);
		monster5->setPosition(Vec2(1200, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(950, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 7)
	{

		auto monster1 = new Monster(6);
		monster1->setPosition(Vec2(700, 345));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(5);
		monster2->setPosition(Vec2(500, 280));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(3);
		monster3->setPosition(Vec2(300, 180));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(1);
		monster5->setPosition(Vec2(500, 180));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(1150, 430));
		this->addChild(totem);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 8)
	{

		auto monster1 = new Monster(2);
		monster1->setPosition(Vec2(400, 355));
		this->addChild(monster1, 1);
		auto monster2 = new Monster(1);
		monster2->setPosition(Vec2(900, 225));
		this->addChild(monster2, 1);
		auto monster3 = new Monster(5);
		monster3->setPosition(Vec2(740, 300));
		this->addChild(monster3, 1);
		auto monster5 = new Monster(6);
		monster5->setPosition(Vec2(1200, 120));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//바디 생성
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동


		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(200, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		initComplete = true;
		log("init %d", stageNum);
	}
	
	else if (stageNum == BOSS_MAP_NUM)
	{

		auto monster1 = new Monster(12);
		monster1->setPosition(Vec2(winsize.width / 2 , winsize.height /2));
		this->addChild(monster1, 1);
		


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage1::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//바디 생성
		this->createMonster(monster1);
		
		this->createPlayer(player);

		this->createBackground();   //배경 이미지 생성
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //카메라 이동

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(750, 430));
		this->addChild(totem);

		int x = rand() % 1000 + 200;
		int y = rand() % 100 + 150;
		auto mud1 = Sprite::create("structure/Rocks.png");
		mud1->setPosition(Vec2(x, y));
		mud1->setScale(0.5);
		this->addChild(mud1);

		x = rand() % 1000 + 200;
		y = rand() % 100 + 150;
		auto mud2 = Sprite::create("structure/Rocks.png");
		mud2->setPosition(Vec2(x, y));
		mud2->setScale(0.5);
		this->addChild(mud2);

		initComplete = true;
		log("init %d", stageNum);
	}
	


	
	
	return true;
}

bool Stage1::createWorld(bool debug)
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
	boxShapeDef.filter.groupIndex = GROUP_INDEX_MONSTER;
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
	groundEdge.Set(b2Vec2(200 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(400 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);
	
	if (stageNum != BOSS_MAP_NUM && this->prev == nullptr) //왼쪽문이 nullptr시
	{
		groundEdge.Set(b2Vec2(400 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(500 / PTM_RATIO, 540 / PTM_RATIO));
		groundBody->CreateFixture(&boxShapeDef);

	}

	//위쪽2
	groundEdge.Set(b2Vec2(500 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1000 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	if (stageNum != BOSS_MAP_NUM && this->next == nullptr) //오른쪽문이 nullptr시
	{
		groundEdge.Set(b2Vec2(1000 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1100 / PTM_RATIO, 540 / PTM_RATIO));
		groundBody->CreateFixture(&boxShapeDef);

	}


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

void Stage1::createPlayer(Sprite * player)
{
	
	//--------------플레이어 바디생성
	b2BodyDef playerBodyDef;
	playerBodyDef.type = b2_dynamicBody;
	playerBodyDef.position.Set(player->getPosition().x / PTM_RATIO, player->getPosition().y / PTM_RATIO);
	playerBodyDef.linearDamping = 30;
	playerBodyDef.userData = player;


	playerBody = _world->CreateBody(&playerBodyDef);

	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);

	b2PolygonShape playerPolygon;
	playerPolygon.SetAsBox((player->getContentSize().width /6) / PTM_RATIO, (player->getContentSize().height / 2) / PTM_RATIO);

	b2FixtureDef playerFixtureDef;
	playerFixtureDef.shape = &playerPolygon;
	playerFixtureDef.density = 0.0f;
	playerFixtureDef.filter.groupIndex = GROUP_INDEX_PLAYER;
	playerFixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	playerFixtureDef.filter.maskBits = CATEGORY_MONSTER;
	playerBody->CreateFixture(&playerFixtureDef);

}

void Stage1::createMonster(Sprite * monster)
{
	//--------------플레이어 바디생성
	b2BodyDef monsterBodyDef;
	monsterBodyDef.type = b2_dynamicBody;
	monsterBodyDef.position.Set(monster->getPosition().x / PTM_RATIO, monster->getPosition().y / PTM_RATIO);
	monsterBodyDef.linearDamping = 20;
	monsterBodyDef.userData = monster;


	auto monsterBody = _world->CreateBody(&monsterBodyDef);

	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);

	b2PolygonShape monsterPolygon;
	monsterPolygon.SetAsBox((monster->getContentSize().width / 3) / PTM_RATIO, (monster->getContentSize().height / 3) / PTM_RATIO);
	//log(" %f ", (monster->getContentSize().height / 2.5));

	b2FixtureDef monsterFixtureDef;
	monsterFixtureDef.shape = &monsterPolygon;
	monsterFixtureDef.density = 0.1f;
	monsterFixtureDef.restitution = 0.3;
	
	monsterFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	monsterFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	monsterFixtureDef.filter.maskBits = CATEGORY_PLAYER + CATEGORY_GROUND;

	monsterBody->SetFixedRotation(true);
	monsterBody->CreateFixture(&monsterFixtureDef);
	monsterBodyVector.push_back(monsterBody);
	auto mon = (Monster*)monster;
	mon->IdleAction();
}

void Stage1::createBackground()
{
	if (stageNum == BOSS_MAP_NUM)
	{
		auto bg = Sprite::create("stage/stage-boss.png");
		bg->setAnchorPoint(Vec2(0, 0));
		bg->setPosition(Vec2(0, 100));
		this->addChild(bg, 0);
	}
	else
	{
		auto bg = Sprite::create("stage/stage-1.png");
		bg->setAnchorPoint(Vec2(0, 0));
		bg->setPosition(Vec2(0, 100));
		this->addChild(bg, 0);

	}

	if (stageNum != BOSS_MAP_NUM && this->prev == nullptr) //왼쪽문이 nullptr시
	{
		
	}
	else if (this->stageNum == BOSS_MAP_NUM)
	{
		
			auto door1 = Sprite::create("structure/door.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(380, 390));
			this->addChild(door1, 0);
		
	}
	else
	{
		if (this->prev->stageNum == BOSS_MAP_NUM) //다음맵의 보스맵일 경우
		{
			auto door1 = Sprite::create("structure/bossdoor.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(380, 390));
			this->addChild(door1, 0);

			auto bossEye = Sprite::create("structure/bosseyes.png");
			bossEye->setPosition(Vec2(door1->getContentSize().width / 2, door1->getContentSize().height / 2 + 30));
			door1->addChild(bossEye);

			auto seq = Sequence::create(FadeOut::create(0.1), FadeIn::create(0.1), DelayTime::create(0.3), nullptr);
			auto seqR = RepeatForever::create(seq);
			bossEye->runAction(seqR);
		}
		else if (false) //아이템 성소일시
		{

		}
		else
		{
			auto door1 = Sprite::create("structure/door.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(380, 390));
			this->addChild(door1, 0);
		}
	}

	if (stageNum != BOSS_MAP_NUM && this->next == nullptr) //오른쪽문이 nullptr시
	{

	}
	else if (this->stageNum == BOSS_MAP_NUM)
	{
		
			auto door1 = Sprite::create("structure/door.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(985, 390));
			this->addChild(door1, 0);
		
	}
	else
	{
		if (this->next->stageNum == BOSS_MAP_NUM)
		{
			auto door1 = Sprite::create("structure/bossdoor.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(985, 390));
			this->addChild(door1, 0);

			auto bossEye = Sprite::create("structure/bosseyes.png");
			bossEye->setPosition(Vec2(door1->getContentSize().width / 2, door1->getContentSize().height / 2 + 30));
			door1->addChild(bossEye);

			auto seq = Sequence::create(FadeOut::create(0.1), FadeIn::create(0.1), DelayTime::create(0.3), nullptr);
			auto seqR = RepeatForever::create(seq);
			bossEye->runAction(seqR);
		}
		else if(false) //아이템 성소일시
		{

		}
		else
		{
			auto door1 = Sprite::create("structure/door.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(985, 390));
			this->addChild(door1, 0);
		}

	}

	if (stageNum != BOSS_MAP_NUM && this->prev == nullptr) //왼쪽문이 nullptr시
	{


	}
	else
	{
		auto steelbar = Sprite::create("structure/steelbar.png", Rect(0, 0, 100, 163));
		steelbar->setAnchorPoint(Vec2(0.65, 0.75));
		this->addChild(steelbar);
		b2BodyDef leftLockDef;
		leftLockDef.type = b2_kinematicBody;
		leftLockDef.position.Set(450 / PTM_RATIO, 540 / PTM_RATIO);
		leftLockDef.userData = steelbar;

		leftLockBody = _world->CreateBody(&leftLockDef);

		b2PolygonShape leftLockBox;
		leftLockBox.SetAsBox(100 / PTM_RATIO, 0);

		b2FixtureDef leftLockFixture;
		leftLockFixture.shape = &leftLockBox;
		leftLockFixture.density = 1.0f;
		leftLockFixture.filter.categoryBits = CATEGORY_GROUND;
		leftLockFixture.filter.maskBits = CATEGORY_MONSTER + CATEGORY_PLAYER;

		leftLockBody->CreateFixture(&leftLockFixture);
		doorBodyVector.push_back(leftLockBody);

	}




	if (stageNum != BOSS_MAP_NUM && this->next == nullptr) //오른쪽문이 nullptr시
	{


	}
	else
	{
		auto steelbar = Sprite::create("structure/steelbar.png", Rect(0, 0, 100, 163));
		steelbar->setAnchorPoint(Vec2(0.35, 0.75));
		this->addChild(steelbar);
		b2BodyDef rightLockDef;
		rightLockDef.type = b2_kinematicBody;
		rightLockDef.position.Set(1050 / PTM_RATIO, 540 / PTM_RATIO);
		rightLockDef.userData = steelbar;

		rightLockBody = _world->CreateBody(&rightLockDef);

		b2PolygonShape rightLockBox;
		rightLockBox.SetAsBox(100 / PTM_RATIO, 0);

		b2FixtureDef rightLockFixture;
		rightLockFixture.shape = &rightLockBox;
		rightLockFixture.density = 1.0f;
		rightLockFixture.filter.categoryBits = CATEGORY_GROUND;
		rightLockFixture.filter.maskBits = CATEGORY_MONSTER + CATEGORY_PLAYER;

		rightLockBody->CreateFixture(&rightLockFixture);
		doorBodyVector.push_back(rightLockBody);
	}

	
}


Stage1::~Stage1()
{
	delete _world;
	_world = nullptr;
	

}


void Stage1::onEnter()
{
	Layer::onEnter();

}
//
//void Stage1::onExit()
//{
//	_eventDispatcher->removeAllEventListeners();
//	Layer::onExit();
//}


void Stage1::draw(Renderer * renderer, const Mat4 & transform, uint32_t flags)
{
	//Layer::draw();
	Layer::draw(renderer, transform, flags);
GL:ccGLEnableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION);

	kmGLPushMatrix();
	_world->DrawDebugData();
	kmGLPopMatrix();


}

void Stage1::tick(float dt)
{
	//물리적 위치를 이용해 그래픽 위치는 갱신한다.

	//velocityIterations : 바디들을 정상적으로 이동시키기 위해 필요한 충돌들을
	//반복적으로 계산
	//positionIterations : 조인트 분리와 겹침 현상을 줄이기 위해 바디의 위치를
	//반복적으로 적용
	//값이 클수록 정확한 연산이 가능하지만 성능이 떨어진다.

	//메뉴얼 상의 권장값
	int velocityIterations = 8;
	int positionIterations = 4;

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
				float vx = joystickVelocity1->x * 5;//스피드
				float vy = joystickVelocity1->y * 5;
				//set ball velocity by Joystick
				b->SetLinearVelocity(b2Vec2(vx, vy) + (b->GetLinearVelocity()));

			}


		}


	}


	//------------------------------------------------------미사일 바디 삭제와 벡터에서의 바디 삭제
	for (int i = 0; i < missileBodyVector.size(); i++)
	{

		if (missileBodyVector[i]->GetUserData() == nullptr)
		{
			_world->DestroyBody(missileBodyVector[i]);
			missileBodyVector.erase(missileBodyVector.begin() + i);

		}


	}



	//------------------------------------------------------- 몬스터 바디 삭제
	for (int i = 0; i < monsterBodyVector.size(); i++)
	{

		if (monsterBodyVector[i]->GetUserData() == nullptr)
		{


			_world->DestroyBody(monsterBodyVector[i]);


			monsterBodyVector.erase(monsterBodyVector.begin() + i);
		}

	}


	//------------------------------------------------------------------ 문 제거
	if (monsterBodyVector.size() == 0 && doorOpen == false)
	{
		auto texture = Director::getInstance()->getTextureCache()->addImage("structure/steelbar.png");
		auto animation = Animation::create();
		animation->setDelayPerUnit(0.1);
		animation->addSpriteFrameWithTexture(texture, Rect(0, 0, 100, 163));
		animation->addSpriteFrameWithTexture(texture, Rect(100, 0, 100, 163));
		animation->addSpriteFrameWithTexture(texture, Rect(200, 0, 100, 163));
		animation->addSpriteFrameWithTexture(texture, Rect(300, 0, 100, 163));
		auto animate = Animate::create(animation);
		auto seq = Sequence::create(animate, RemoveSelf::create(), nullptr);
		for (int i = 0; i < doorBodyVector.size(); i++)
		{
			((Sprite*)(doorBodyVector.at(i)->GetUserData()))->runAction(seq->clone());
			_world->DestroyBody(doorBodyVector.at(i));
		}
		doorBodyVector.clear();
		doorOpen = true;
	}



	//-------------------------------------------------------------- ZOrder 처리
	for (int i = 0; i < monsterBodyVector.size(); i++)
	{

		Monster *monster = (Monster*)(monsterBodyVector[i]->GetUserData());

		//  충돌 처리
		if (player->getPosition().y < monster->getPosition().y + 30 && player->getPosition().y > monster->getPosition().y - 30)
		{
			//log("dddd");
			b2Filter newFilter;
			b2Filter oldFilter;
			oldFilter.categoryBits = 0x0001;
			oldFilter.maskBits = 0xFFFF;
			oldFilter.groupIndex = 0;
			oldFilter = monsterBodyVector[i]->GetFixtureList()->GetFilterData();
			newFilter = oldFilter;
			newFilter.maskBits = CATEGORY_PLAYER;
			monsterBodyVector[i]->GetFixtureList()->SetFilterData(newFilter);
			//CC_SAFE_DELETE(newFilter);
			//CC_SAFE_DELETE(oldFilter);
		}
		else
		{
			b2Filter newFilter;
			b2Filter oldFilter;
			oldFilter.categoryBits = 0x0001;
			oldFilter.maskBits = 0xFFFF;
			oldFilter.groupIndex = 0;
			oldFilter = monsterBodyVector[i]->GetFixtureList()->GetFilterData();
			newFilter = oldFilter;
			newFilter.maskBits = 0;////////////////////////////////
			monsterBodyVector[i]->GetFixtureList()->SetFilterData(newFilter);
			//CC_SAFE_DELETE(newFilter);
			//CC_SAFE_DELETE(oldFilter);

		}


		if (player->getPosition().y > monster->getPosition().y + 30)
			player->setZOrder(monster->getZOrder() - 1);
		else if (player->getPosition().y < monster->getPosition().y + 30)
			player->setZOrder(monster->getZOrder() + 1);



	}


	//------------------------------------------------------------------- 공격 처리
	if (player->alive == true && player->hitting == true)
	{
		if (joystickVelocity2->x > 0.9)
		{
			LongAttack(RIGHTLONGATTACK);

		}
		else if (joystickVelocity2->x < -0.9)
		{
			LongAttack(LEFTLONGATTACK);
		}
	}


	//------------------------------------------------------------------ 캐릭터 이동
	if (player->alive == true)
	{
		// 캐릭터 이동 관련 부분
		if (joystickVelocity1->x == 0 && joystickVelocity1->y == 0 && count == 0)
		{

			//player->stopAllActions();
			player->IdleAction();
			count = 1;

		}
		else if (joystickVelocity1->x < 0)
		{
			//log("%f", joystick1->getVelocity().x);
			if (count == 1)
			{
				//player->stopAllActions();
				player->MoveAction();
				count = 0;
			}
			player->setFlippedX(true);

		}
		else if (joystickVelocity1->x > 0)
		{
			//log("%f", joystick1->getVelocity().x);
			if (count == 1)
			{
				//player->stopAllActions();
				player->MoveAction();
				count = 0;
			}
			player->setFlippedX(false);

		}
	}
	//------------------------------------------------------------------  A.I
	if (isAiOn == false )
	{
		this->scheduleOnce(schedule_selector(Stage1::AITick), 1);
		isAiOn = true;
	}
	

}
void Stage1::BossTick(float dt)
{
	auto playerPosition = player->getPosition();
	/////////////////////////////         보스 작업 필요
	this->MakeBossMissile1(1, 0, 1);
	this->MakeBossMissile1(2, 1, 1);
	this->MakeBossMissile1(3, 1, 0);
	this->MakeBossMissile1(4, 1, -1);
	this->MakeBossMissile1(5, 0, -1);
	this->MakeBossMissile1(6, -1, -1);
	this->MakeBossMissile1(7, -1, 0);
	this->MakeBossMissile1(8, -1, 1);
}

void Stage1::AITick(float dt)
{
	if (stageNum == 9)
	{
		this->schedule(schedule_selector(Stage1::BossTick),1);
	}
	else 
	{
		this->schedule(schedule_selector(Stage1::AITick2));
	}

}
void Stage1::AITick2(float dt)
{
	auto playerPosition = player->getPosition();

	for (int i = 0; i < monsterBodyVector.size(); i++)
	{
		auto x = playerBody->GetPosition().x - monsterBodyVector.at(i)->GetPosition().x;
		auto y = playerBody->GetPosition().y - monsterBodyVector.at(i)->GetPosition().y;
		float xR, yR;
		if (x < 0)
			xR = -2;
		else
			xR = 2;

		if (y < 0)
			yR = -2;
		else
			yR = 2;

		monsterBodyVector.at(i)->SetLinearVelocity(b2Vec2(xR,yR));


	}



}
void Stage1::MakeBossMissile1(int location, float x, float y)
{
	Vec2 position;
	if (location == 1)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x 
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y + 50);
	}
	else if (location == 2)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x+50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y + 50);
	}
	else if (location == 3)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x+50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y );
	}
	else if (location == 4)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x+50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y - 50);
	}
	else if (location == 5)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y - 50);
	}
	else if (location == 6)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x -50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y - 50);
	}
	else if (location == 7)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x -50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y );
	}
	else if (location == 8)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x -50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y + 50);
	}


	BossMissile *missile = new BossMissile(1);
	missile->setPosition(position);
	//missile->setAnchorPoint(Vec2(0.8, 0.5));
	this->addChild(missile);
	missile->startAction();
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
	b2CircleShape circle;
	circle.m_radius = 0.45f;
	


	b2FixtureDef missileFixtureDef;
	missileFixtureDef.shape = &circle;
	missileFixtureDef.density = 1.0f;
	missileFixtureDef.restitution = 0.5;
	//missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	missileFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	missileFixtureDef.filter.maskBits = CATEGORY_PLAYER;
	//missileBody->SetFixedRotation(true);
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(x, y));
	monsterMissileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
}



void Stage1::LongAttack(int num)
{
	switch (num)
	{
	case RIGHTLONGATTACK:
	
		if (!this->isScheduled(schedule_selector(Stage1::RightLongAttack)) &&
			!this->isScheduled(schedule_selector(Stage1::clearTime)))
		{
			this->RightLongAttack(0);
		}
		else if (!this->isScheduled(schedule_selector(Stage1::RightLongAttack)))
			this->scheduleOnce(schedule_selector(Stage1::RightLongAttack), player->attackSpeed);
		break;


	case LEFTLONGATTACK:
		if (!this->isScheduled(schedule_selector(Stage1::LeftLongAttack)) &&
			!this->isScheduled(schedule_selector(Stage1::clearTime)))
		{
			this->LeftLongAttack(0);
		}
		else if (!this->isScheduled(schedule_selector(Stage1::LeftLongAttack)))
			this->scheduleOnce(schedule_selector(Stage1::LeftLongAttack), player->attackSpeed);
		break;
	}
}

void Stage1::RightLongAttack(float dt)
{
	log("오른쪽 검기");

	SwordMissile *missile = new SwordMissile(1);
	missile->setPosition(Vec2(player->getPosition().x + 50.f, player->getPosition().y));
	missile->setFlipX(true);
	missile->setAnchorPoint(Vec2(0.8, 0.5));
	this->addChild(missile);
	player->stopAllActions();
	player->setFlippedX(false);
	player->AttackAction();
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
	missileFixtureDef.density = 1.0f;
	missileFixtureDef.restitution = 0.5;
	missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	missileFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	missileFixtureDef.filter.maskBits = CATEGORY_MONSTER;
	//missileBody->SetFixedRotation(true);
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(10, 0));
	missileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
	this->scheduleOnce(schedule_selector(Stage1::clearTime), player->attackSpeed);

}
void Stage1::LeftLongAttack(float dt)
{
	

	SwordMissile *missile = new SwordMissile(1);
	missile->setPosition(Vec2(player->getPosition().x - 50.f, player->getPosition().y));
	this->addChild(missile);
	player->stopAllActions();
	player->setFlippedX(true);
	missile->setAnchorPoint(Vec2(0.2, 0.5));
	player->AttackAction();
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
	missileFixtureDef.density = 1.0f;
	missileFixtureDef.restitution = 0.5;
	missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	missileFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	missileFixtureDef.filter.maskBits = CATEGORY_MONSTER;
	//missileBody->SetFixedRotation(true);
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(-10, 0));
	missileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
	this->scheduleOnce(schedule_selector(Stage1::clearTime), player->attackSpeed);

}

void Stage1::clearTime(float dt)
{
}
