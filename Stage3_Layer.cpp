#include "Stage3_Layer.h"
#include "Gameover.h"
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


Scene* Stage3_Layer::createScene()
{

	auto scene = Scene::create();
	auto layer = Stage3_Layer::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Stage3_Layer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	srand((unsigned)time(nullptr));
	winsize = Director::getInstance()->getWinSize();



	player = new Player();
	//player = new Player();
	//this->addChild(player,1);
	//this->runAction(Follow::create(player,Rect(0, 0,1500, 720)));



	//bgLayer = new BackgroundLayer();
	//bgLayer->init();
	//bgLayer->player = player;
	//
	////플레이어 생성
	//
	//
	//bgLayer->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));

	//
	////----조이스틱 생성


	// 조이스틱 1
	kCenter1 = Vec2(150, 120);

	velocity1 = Vec2::ZERO;

	Sprite* bg1 = Sprite::create("joystick_background.png");
	bg1->setPosition(kCenter1);
	bg1->setScale(0.7);
	this->addChild(bg1, 2);

	thumb1 = Sprite::create("joystick_thumb.png");
	thumb1->setPosition(kCenter1);
	this->addChild(thumb1, 3);

	auto upBar = Sprite::create("ui/bar.png");
	upBar->setPosition(Vec2(winsize.width / 2, winsize.height));
	upBar->setAnchorPoint(Vec2(0.5, 1));
	this->addChild(upBar, 1);

	auto downBar = Sprite::create("ui/bar.png");
	downBar->setPosition(Vec2(winsize.width / 2, 0));
	downBar->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(downBar, 1);

	auto itemBox = MenuItemImage::create("ui/itemBox.png", "ui/itemBox.png", CC_CALLBACK_1(Stage3_Layer::ItemUse, this));
	auto pItemMenu = Menu::create(itemBox, nullptr);
	pItemMenu->setPosition(Vec2(winsize.width - 80, winsize.height - 80));
	this->addChild(pItemMenu, 3);

	upBar->addChild(player->energy, 2);
	upBar->addChild(player->magicEnergy, 2);

	//////////////////////////////////////////////////////

	itemSprite = Sprite::create("item/active/redstar.png");
	itemSprite->setVisible(false);
	itemSprite->setPosition(Vec2(itemBox->getContentSize().width / 2, itemBox->getContentSize().height / 2));
	itemBox->addChild(itemSprite);

	auto menuItem = MenuItemImage::create("menu/config_button.png", "menu/config_button_pressed.png", CC_CALLBACK_1(Stage3_Layer::OpenMenu, this));
	auto menu = Menu::create(menuItem, nullptr);
	menuItem->setAnchorPoint(Vec2(0, 1));
	menu->setPosition(Vec2(0, upBar->getContentSize().height));
	upBar->addChild(menu);

	//auto energy = Sprite::create("ui/meter-06.png");
	//energy->setPosition(Vec2(upBar->getContentSize().height / 2, 50));
	//energy->setAnchorPoint(Vec2( 0, 0.5));
	//upBar->addChild(energy);



	// 조이스틱 2
	kCenter2 = Vec2(winsize.width - 150, 120);


	velocity2 = Vec2::ZERO;

	Sprite* bg2 = Sprite::create("joystick_background.png");
	bg2->setPosition(kCenter2);
	bg2->setScale(0.7);
	this->addChild(bg2, 1);

	thumb2 = Sprite::create("joystick_thumb.png");
	thumb2->setPosition(kCenter2);
	this->addChild(thumb2, 2);



	this->MakeMap();

	//auto bgLayer1 = new Stage3();//생성자 넣기
	//bgLayer1->stageNum=1;
	//bgLayer1->joystickVelocity1 = &velocity1;
	//bgLayer1->joystickVelocity2 = &velocity2;
	//bgLayer1->joystickIspressed1 = &isPressed1;
	//bgLayer1->joystickIspressed2 = &isPressed2;
	//bgLayer1->player = player;
	//bgLayer1->addChild(player);
	//bgLayer1->init();


	//---------------------------------------------------------------------

	stage.at(0)->init();
	this->addChild(stage.at(0), 0);

	//stage.at(9)->init();
	//this->addChild(stage.at(9), 0);

	this->schedule(schedule_selector(Stage3_Layer::tick));
	return true;
}
void Stage3_Layer::OpenMenu(Ref *p)
{
	SimpleAudioEngine::getInstance()->playEffect(CLICK);
	//auto menuScene = MenuScene::createScene();
	auto menuScene = new MenuScene();
	menuScene->init();
	menuScene->autorelease();
	Director::getInstance()->pause();
	this->addChild(menuScene, 10);
}

static bool isPointInCircle(Vec2 point, Vec2 center, float radius)
{
	float dx = (point.x - center.x);
	float dy = (point.y - center.y);
	return (radius >= sqrt((dx*dx) + (dy*dy)));
}

void Stage3_Layer::MakeMap()
{
	//-----------------스테이지 객체 생성------------------

	auto bgLayer1 = new Stage3();//생성자 넣기
	bgLayer1->joystickVelocity1 = &velocity1;
	bgLayer1->joystickVelocity2 = &velocity2;
	bgLayer1->joystickIspressed1 = &isPressed1;
	bgLayer1->joystickIspressed2 = &isPressed2;
	bgLayer1->player = player;
	bgLayer1->addChild(player, 3);


	auto bgLayer2 = new Stage3();
	bgLayer2->joystickVelocity1 = &velocity1;
	bgLayer2->joystickVelocity2 = &velocity2;
	bgLayer2->joystickIspressed1 = &isPressed1;
	bgLayer2->joystickIspressed2 = &isPressed2;

	auto bgLayer3 = new Stage3();
	bgLayer3->joystickVelocity1 = &velocity1;
	bgLayer3->joystickVelocity2 = &velocity2;
	bgLayer3->joystickIspressed1 = &isPressed1;
	bgLayer3->joystickIspressed2 = &isPressed2;

	auto bgLayer4 = new Stage3();
	bgLayer4->joystickVelocity1 = &velocity1;
	bgLayer4->joystickVelocity2 = &velocity2;
	bgLayer4->joystickIspressed1 = &isPressed1;
	bgLayer4->joystickIspressed2 = &isPressed2;

	auto bgLayer5 = new Stage3();
	bgLayer5->joystickVelocity1 = &velocity1;
	bgLayer5->joystickVelocity2 = &velocity2;
	bgLayer5->joystickIspressed1 = &isPressed1;
	bgLayer5->joystickIspressed2 = &isPressed2;

	auto bgLayer6 = new Stage3();
	bgLayer6->joystickVelocity1 = &velocity1;
	bgLayer6->joystickVelocity2 = &velocity2;
	bgLayer6->joystickIspressed1 = &isPressed1;
	bgLayer6->joystickIspressed2 = &isPressed2;

	auto bgLayer7 = new Stage3();
	bgLayer7->joystickVelocity1 = &velocity1;
	bgLayer7->joystickVelocity2 = &velocity2;
	bgLayer7->joystickIspressed1 = &isPressed1;
	bgLayer7->joystickIspressed2 = &isPressed2;

	auto bgLayer8 = new Stage3();
	bgLayer8->joystickVelocity1 = &velocity1;
	bgLayer8->joystickVelocity2 = &velocity2;
	bgLayer8->joystickIspressed1 = &isPressed1;
	bgLayer8->joystickIspressed2 = &isPressed2;

	auto bgLayer9 = new Stage3();
	bgLayer9->joystickVelocity1 = &velocity1;
	bgLayer9->joystickVelocity2 = &velocity2;
	bgLayer9->joystickIspressed1 = &isPressed1;
	bgLayer9->joystickIspressed2 = &isPressed2;

	auto bgLayer10 = new Stage3();
	bgLayer10->joystickVelocity1 = &velocity1;
	bgLayer10->joystickVelocity2 = &velocity2;
	bgLayer10->joystickIspressed1 = &isPressed1;
	bgLayer10->joystickIspressed2 = &isPressed2;

	auto bgLayer11 = new Stage3();
	bgLayer11->joystickVelocity1 = &velocity1;
	bgLayer11->joystickVelocity2 = &velocity2;
	bgLayer11->joystickIspressed1 = &isPressed1;
	bgLayer11->joystickIspressed2 = &isPressed2;

	auto bgLayer12 = new Stage3();
	bgLayer12->joystickVelocity1 = &velocity1;
	bgLayer12->joystickVelocity2 = &velocity2;
	bgLayer12->joystickIspressed1 = &isPressed1;
	bgLayer12->joystickIspressed2 = &isPressed2;

	auto bgLayer13 = new Stage3();
	bgLayer13->joystickVelocity1 = &velocity1;
	bgLayer13->joystickVelocity2 = &velocity2;
	bgLayer13->joystickIspressed1 = &isPressed1;
	bgLayer13->joystickIspressed2 = &isPressed2;

	auto bgLayer14 = new Stage3();
	bgLayer14->joystickVelocity1 = &velocity1;
	bgLayer14->joystickVelocity2 = &velocity2;
	bgLayer14->joystickIspressed1 = &isPressed1;
	bgLayer14->joystickIspressed2 = &isPressed2;

	auto bgLayer15 = new Stage3();
	bgLayer15->joystickVelocity1 = &velocity1;
	bgLayer15->joystickVelocity2 = &velocity2;
	bgLayer15->joystickIspressed1 = &isPressed1;
	bgLayer15->joystickIspressed2 = &isPressed2;

	auto bgLayer16 = new Stage3();
	bgLayer16->joystickVelocity1 = &velocity1;
	bgLayer16->joystickVelocity2 = &velocity2;
	bgLayer16->joystickIspressed1 = &isPressed1;
	bgLayer16->joystickIspressed2 = &isPressed2;
	//bgLayer10->player = player;
	//bgLayer10->addChild(player,3);
	//-------------------------------백터에 스테이지 넣기------------------

	player->nowStage = bgLayer1;

	stage.push_back(bgLayer1);
	stage.push_back(bgLayer2);
	stage.push_back(bgLayer3);
	stage.push_back(bgLayer4);
	stage.push_back(bgLayer5);
	stage.push_back(bgLayer6);
	stage.push_back(bgLayer7);
	stage.push_back(bgLayer8);
	stage.push_back(bgLayer9);
	stage.push_back(bgLayer10);
	stage.push_back(bgLayer11);
	stage.push_back(bgLayer12);
	stage.push_back(bgLayer13);
	stage.push_back(bgLayer14);
	stage.push_back(bgLayer15);
	stage.push_back(bgLayer16);



	//던전 넘버 설정
	for (int i = 0; i < stage.size(); i++)
	{
		stage.at(i)->stageNum = i;

	}

	while (1)
	{
		int num = rand() % (stage.size() - 2) + 1;  // 1~4
		if (check[num] != 0)
			continue;
		else
		{
			stage.at(0)->prev = stage.at(num);
			check[num]++;
			break;
		}
	}
	while (1)
	{
		int num = rand() % (stage.size() - 2) + 1;  // 1~4
		if (check[num] != 0)
			continue;
		else
		{
			stage.at(0)->next = stage.at(num);
			check[num]++;
			break;
		}
	}

	int num = (stage.size() - 2) / 2;
	int ran = rand() % 2 == 0;
	log("%d", ran);
	if (ran)
	{
		this->MakeMapRamdom(stage.at(0)->prev, stage.at(0), num, true);  //prev
		this->MakeMapRamdom(stage.at(0)->next, stage.at(0), num, false);  //next
	}
	else
	{
		this->MakeMapRamdom(stage.at(0)->next, stage.at(0), num, false);  //next
		this->MakeMapRamdom(stage.at(0)->prev, stage.at(0), num, true);  //prev
	}



	log("Map Make Done");
}
void Stage3_Layer::MakeMapRamdom(Stage3 *nowStage, Stage3 *preStage, int num, bool state)
{
	num--;
	if (num == 0)
	{
		if (state == true)
		{
			nowStage->next = preStage;
		}
		else if (state == false)
		{
			nowStage->prev = preStage;
		}
		if (check[stage.size() - 1] != 1)
		{
			if (state == true)
			{
				nowStage->prev = stage.at(stage.size() - 1);
				stage.at(stage.size() - 1)->next = nowStage;
			}
			else
			{
				nowStage->next = stage.at(stage.size() - 1);
				stage.at(stage.size() - 1)->prev = nowStage;
			}

			check[stage.size() - 1]++;

		}

		return;

	}

	if (state == true)
	{
		nowStage->next = preStage;
		while (1)
		{
			int num = rand() % (stage.size() - 2) + 1;  // 1~4
			if (check[num] != 0)
				continue;
			else
			{
				nowStage->prev = stage.at(num);
				check[num]++;
				break;
			}
		}
		this->MakeMapRamdom(nowStage->prev, nowStage, num, true);

	}
	else if (state == false)
	{
		nowStage->prev = preStage;
		while (1)
		{
			int num = rand() % (stage.size() - 2) + 1;  // 1~4
			if (check[num] != 0)
				continue;
			else
			{
				nowStage->next = stage.at(num);
				check[num]++;
				break;
			}
		}
		this->MakeMapRamdom(nowStage->next, nowStage, num, false);

	}

}

void Stage3_Layer::updateVelocity1(Vec2 point)
{
	// calculate Angle and length
	float dx = point.x - kCenter1.x;
	float dy = point.y - kCenter1.y;

	float distance = sqrt(dx*dx + dy*dy);
	float angle = atan2(dy, dx); // in radians

	if (dx != 0 && dy != 0)
	{
		dx = cos(angle) * JOYSTICK_RADIUS;
		dy = sin(angle) * JOYSTICK_RADIUS;
	}

	velocity1 = Vec2((dx) / JOYSTICK_RADIUS, (dy) / JOYSTICK_RADIUS);

	if (distance>THUMB_RADIUS)
	{
		point.x = kCenter1.x + cos(angle) * THUMB_RADIUS;
		point.y = kCenter1.y + sin(angle) * THUMB_RADIUS;
	}

	thumb1->setPosition(point);
}
void Stage3_Layer::updateVelocity2(Vec2 point)
{
	// calculate Angle and length
	float dx = point.x - kCenter2.x;
	float dy = point.y - kCenter2.y;

	float distance = sqrt(dx*dx + dy*dy);
	float angle = atan2(dy, dx); // in radians

	if (distance > JOYSTICK_RADIUS)
	{
		dx = cos(angle) * JOYSTICK_RADIUS;
		dy = sin(angle) * JOYSTICK_RADIUS;
	}

	velocity2 = Vec2((dx) / JOYSTICK_RADIUS, (dy) / JOYSTICK_RADIUS);

	if (distance>THUMB_RADIUS)
	{
		point.x = kCenter2.x + cos(angle) * THUMB_RADIUS;
		point.y = kCenter2.y + sin(angle) * THUMB_RADIUS;
	}

	thumb2->setPosition(point);
}

void Stage3_Layer::resetJoystick1()
{
	this->updateVelocity1(kCenter1);
}
void Stage3_Layer::resetJoystick2()
{
	log("2");

	this->updateVelocity2(kCenter2);
}

bool Stage3_Layer::handleLastTouch1()
{
	bool wasPressed = isPressed1;



	if (wasPressed)
	{
		this->resetJoystick1();
		isPressed1 = false;
	}
	return (wasPressed ? true : false);
}
bool Stage3_Layer::handleLastTouch2()
{
	bool wasPressed = isPressed2;



	if (wasPressed)
	{
		this->resetJoystick2();
		isPressed2 = false;
	}
	return (wasPressed ? true : false);
}

void Stage3_Layer::tick(float dt)
{

	if (player->getPosition().x > 1000 && player->getPosition().x < 1100 && player->getPosition().y > 480) // 오른쪽문
	{
		auto nowPlayerStage = (Stage3*)(player->nowStage);
		auto nextPlayerStage = ((Stage3*)(player->nowStage))->next;
		if (nowPlayerStage->next == nullptr)
		{
			auto pScene = Gameover::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, pScene));

		}
		else if (nowPlayerStage->next->initComplete == false)
		{

			//-----------플레이어의 현재 스테이지를 바꾸고 현재스테이지는 제거한다.
			player->nowStage = nextPlayerStage;
			nowPlayerStage->removeChild(player, false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);
			nextPlayerStage->player = player;

			//-----------플레이어의 포지션을 정하고 다음 스테이지를 불러온다.
			player->setPosition(Vec2(450, 450));
			this->addChild(nextPlayerStage);
			nextPlayerStage->init();
			nextPlayerStage->addChild(player);
		}
		else
		{
			//------------현재 스테이지 제거
			player->nowStage = nextPlayerStage;
			nowPlayerStage->removeChild(player, false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);

			//------------다음 스테이지 불러옴
			player->setPosition(Vec2(450, 450));
			nextPlayerStage->addChild(player);
			nextPlayerStage->createPlayer(player);
			this->addChild(nextPlayerStage);


		}


	}
	else if (player->getPosition().x > 400 && player->getPosition().x < 500 && player->getPosition().y > 480) // 왼쪽문
	{

		auto nowPlayerStage = (Stage3*)(player->nowStage);
		auto prevPlayerStage = ((Stage3*)(player->nowStage))->prev;
		if (nowPlayerStage->prev == nullptr)
		{
			auto pScene = Gameover::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, pScene));
		}
		else if (nowPlayerStage->prev->initComplete == false)
		{

			//-----------플레이어의 현재 스테이지를 바꾸고 현재스테이지는 제거한다.
			player->nowStage = prevPlayerStage;
			nowPlayerStage->removeChild(player, false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);
			prevPlayerStage->player = player;

			//-----------플레이어의 포지션을 정하고 다음 스테이지를 불러온다.
			player->setPosition(Vec2(1050, 430));
			this->addChild(prevPlayerStage);
			prevPlayerStage->init();
			prevPlayerStage->addChild(player);
		}
		else
		{
			//------------현재 스테이지 제거
			player->nowStage = prevPlayerStage;
			nowPlayerStage->removeChild(player, false);
			nowPlayerStage->_world->DestroyBody(nowPlayerStage->playerBody);
			this->removeChild(nowPlayerStage, false);

			//------------다음 스테이지 불러옴
			player->setPosition(Vec2(1050, 430));
			prevPlayerStage->addChild(player);
			prevPlayerStage->createPlayer(player);
			this->addChild(prevPlayerStage);


		}
	}

	if (((Stage3*)(player->nowStage))->stageNum == BOSS_MAP_NUM3) //보스 스테이지
	{

		if (isProgressOn == false)
		{
			auto bossenergy = Sprite::create("ui/bossenergy.png");
			pt = ProgressTimer::create(bossenergy);
			pt->setType(ProgressTimer::Type::BAR);
			pt->setPosition(Vec2(winsize.width / 2, winsize.height - 100));
			pt->setMidpoint(Vec2(0, 0));
			pt->setBarChangeRate(Vec2(1, 0));
			log("progress");
			this->addChild(pt);
			isProgressOn = true;

			log("progress2");
		}
		vector<b2Body*> temp = ((Stage3*)(player->nowStage))->monsterBodyVector;

		for (int i = 0; i < temp.size(); i++)
		{
			if (((Monster*)(temp.at(i)->GetUserData())) != nullptr)
			{
				float bossEnergy = ((Monster*)(temp.at(i)->GetUserData()))->nowEnergy;
				float bossMaxEnergy = ((Monster*)(temp.at(i)->GetUserData()))->maxEnergy;
				float f = (bossEnergy / bossMaxEnergy) * 100;

				pt->setPercentage(f);
			}
		}
		if (temp.size() == 0)
		{
			pt->setPercentage(0);
		}

	}

	if (player->activeItem == 1)
	{
		itemSprite->setTexture("item/active/lighter.png");
		itemSprite->setVisible(true);
	}
	else if (player->activeItem == 2)
	{
		itemSprite->setTexture("item/active/redstar.png");
		itemSprite->setVisible(true);
	}
	else if (player->activeItem == 3)
	{
		itemSprite->setTexture("item/active/saw.png");
		itemSprite->setVisible(true);
	}
	else if (player->activeItem == 4)
	{
		itemSprite->setTexture("item/active/spiderweb.png");
		itemSprite->setVisible(true);
	}

}

void Stage3_Layer::ItemUse(Ref * p)
{
	log("item click");
	if (player->activeItem == 1 && player->nowMagic > 7)
	{
		SimpleAudioEngine::getInstance()->playEffect(ITEM_USE);
		auto nowPlayerStage = (Stage3*)(player->nowStage);
		auto monster = nowPlayerStage->monsterBodyVector;

		for (int i = 0; i < monster.size(); i++)
		{
			auto monsterSprite = (Monster*)(monster.at(i)->GetUserData());

			monsterSprite->nowEnergy -= 10;
			if (monsterSprite->nowEnergy <= 0)
			{
				//monsterSprite->isAlive = false;
				monsterSprite->DeadAction();
				monster.at(i)->SetUserData(nullptr);
			}
			else
				monsterSprite->HittedAction();
		}
		//player->nowMagic -= 8;
		player->magicEnergy->setTexture2(player->nowMagic);

	}
	if (player->activeItem == 2 && player->nowMagic > 5)
	{
		SimpleAudioEngine::getInstance()->playEffect(ITEM_USE);
		player->power += 5;


		player->attackSpeed += -0.09;


		player->missileSpeed += 10;


		player->nukBack += 5;

		player->nowMagic -= 6;
		player->magicEnergy->setTexture2(player->nowMagic);

		this->scheduleOnce(schedule_selector(Stage3_Layer::resetStat), 5);

	}
	if (player->activeItem == 3 && player->nowMagic > 4)
	{
		SimpleAudioEngine::getInstance()->playEffect(ITEM_USE);
		player->power += 10;


		player->attackSpeed += 0.2;


		player->missileSpeed += 10;


		player->nukBack += 15;

		player->nowMagic -= 5;
		player->magicEnergy->setTexture2(player->nowMagic);

		this->scheduleOnce(schedule_selector(Stage3_Layer::resetStat), 5);

	}
	if (player->activeItem == 4 && player->nowMagic > 1)
	{
		SimpleAudioEngine::getInstance()->playEffect(ITEM_USE);
		auto nowPlayerStage = (Stage3*)(player->nowStage);
		nowPlayerStage->unschedule(schedule_selector(Stage3::AITick2));
		this->scheduleOnce(schedule_selector(Stage3_Layer::resetStat), 5);

		player->nowMagic -= 2;
		player->magicEnergy->setTexture2(player->nowMagic);
	}

}

void Stage3_Layer::resetStat(float dt)
{
	if (player->activeItem == 2)
	{
		player->power -= 5;
		player->attackSpeed += 0.09;
		player->missileSpeed -= 10;
		player->nukBack -= 5;
	}

	if (player->activeItem == 3)
	{
		player->power -= 10;
		player->attackSpeed += -0.2;
		player->missileSpeed -= 10;
		player->nukBack -= 15;
	}
	if (player->activeItem == 4)
	{
		auto nowPlayerStage = (Stage3*)(player->nowStage);
		nowPlayerStage->schedule(schedule_selector(Stage3::AITick2));

	}
}

void Stage3_Layer::onEnter()
{
	Layer::onEnter();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(STAGE3_BGM, true);
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Stage3_Layer::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(Stage3_Layer::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(Stage3_Layer::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(Stage3_Layer::onTouchesCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

//void Stage3_Layer::onExit()
//{
//	
//	//SimpleAudioEngine::getInstance()->end();
//	Layer::onExit();
//}

void Stage3_Layer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{

		auto touch = item;

		Vec2 point = touch->getLocationInView();
		Vec2 touchPoint = Director::getInstance()->convertToGL(point);


		if (isPointInCircle(touchPoint, kCenter1, JOYSTICK_RADIUS))
		{
			isPressed1 = true;
			touchNum.push_back(touch->getID());
			joyNum[touch->getID()] = 1;

			this->updateVelocity1(touchPoint);

		}
		if (isPointInCircle(touchPoint, kCenter2, JOYSTICK_RADIUS))
		{
			isPressed2 = true;
			touchNum.push_back(touch->getID());
			joyNum[touch->getID()] = 2;

			this->updateVelocity2(touchPoint);
		}

	}



}

void Stage3_Layer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{

		auto touch = item;



		if (isPressed1 && joyNum[touch->getID()] == 1)
		{

			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);

			this->updateVelocity1(touchPoint);

		}
		if (isPressed2 && joyNum[touch->getID()] == 2)
		{

			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);

			this->updateVelocity2(touchPoint);

		}



	}


}

void Stage3_Layer::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
	for (auto &item : touches)
	{
		auto touch = item;

		if (isPressed1 && joyNum[touch->getID()] == 1)
		{
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);
			this->handleLastTouch1();
			joyNum[touch->getID()] = 10;

		}
		if (isPressed2 && joyNum[touch->getID()] == 2)
		{
			Vec2 point = touch->getLocationInView();
			Vec2 touchPoint = Director::getInstance()->convertToGL(point);
			this->handleLastTouch2();
			joyNum[touch->getID()] = 10;

		}





	}

}
