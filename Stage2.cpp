#include "Stage2.h"
#include "Gameover.h"
#include "SimpleAudioEngine.h"


#define PLAYER_SWORD "sounds/player/player_sword.ogg"
#define PLAYER_HITTED "sounds/player/player_hitted.ogg"
#define CLICK "sounds/click/click.ogg"
#define INTRO_BGM "sounds/intro/intro_bgm.ogg"
#define LOBBY_BGM "sounds/lobby/lobby_bgm.ogg"
#define Stage2_BGM "sounds/Stage2/Stage2_bgm.ogg"
#define STAGE2_BGM "sounds/stage2/stage2_bgm.ogg"
#define STAGE3_BGM "sounds/stage3/stage3_bgm.ogg"
#define ITEM_GET "sounds/item/item_get.ogg"
#define ITEM_USE "sounds/item/item_use.ogg"

using namespace CocosDenshion;

USING_NS_CC;

Scene* Stage2::createScene()
{

	auto scene = Scene::create();
	auto layer = Stage2::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Stage2::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	srand((unsigned)time(nullptr));
	missileBodyVector.clear();
	monsterBodyVector.clear();
	winsize = Director::getInstance()->getWinSize();

	//player = new Player();
	//this->addChild(player, 1);

	if (stageNum == 0)
	{
		



		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����

		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

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
		log("init %d", stageNum);

	}
	else if (stageNum == 1)
	{

		auto monster1 = new Monster2(1);
		monster1->setPosition(Vec2(500, 200));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(4);
		monster2->setPosition(Vec2(800, 300));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(3);
		monster3->setPosition(Vec2(1000, 300));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(6);
		monster5->setPosition(Vec2(700, 200));
		this->addChild(monster5, 1);

		auto monster6 = new Monster2(5);
		monster6->setPosition(Vec2(400, 300));
		this->addChild(monster6, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createMonster(monster6);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

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

		auto monster1 = new Monster2(4);
		monster1->setPosition(Vec2(300, 200));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(5);
		monster2->setPosition(Vec2(800, 350));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(8);
		monster3->setPosition(Vec2(1000, 300));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(2);
		monster5->setPosition(Vec2(1000, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

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

		auto monster1 = new Monster2(2);
		monster1->setPosition(Vec2(600, 300));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(4);
		monster2->setPosition(Vec2(700, 250));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(6);
		monster3->setPosition(Vec2(1000, 300));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(8);
		monster5->setPosition(Vec2(300, 300));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�


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

		auto monster1 = new Monster2(3);
		monster1->setPosition(Vec2(600, 200));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(6);
		monster2->setPosition(Vec2(800, 300));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(1);
		monster3->setPosition(Vec2(500, 250));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(5);
		monster5->setPosition(Vec2(470, 290));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�


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

		auto monster1 = new Monster2(1);
		monster1->setPosition(Vec2(300, 300));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(5);
		monster2->setPosition(Vec2(900, 265));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(2);
		monster3->setPosition(Vec2(700, 285));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(8);
		monster5->setPosition(Vec2(100, 250));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

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

		auto monster1 = new Monster2(8);
		monster1->setPosition(Vec2(400, 350));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(6);
		monster2->setPosition(Vec2(700, 270));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(2);
		monster3->setPosition(Vec2(1000, 270));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(4);
		monster5->setPosition(Vec2(1200, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

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

		auto monster1 = new Monster2(6);
		monster1->setPosition(Vec2(700, 345));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(5);
		monster2->setPosition(Vec2(500, 280));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(3);
		monster3->setPosition(Vec2(300, 180));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(1);
		monster5->setPosition(Vec2(500, 180));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(1150, 430));
		this->addChild(totem);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == ITEM_MAP_NUM)
	{




		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����

		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�


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
	else if (stageNum == 9)
	{

		auto monster1 = new Monster2(1);
		monster1->setPosition(Vec2(200, 180));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(3);
		monster2->setPosition(Vec2(400, 280));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(5);
		monster3->setPosition(Vec2(300, 250));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(8);
		monster5->setPosition(Vec2(500, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(1150, 430));
		this->addChild(totem);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 10)
	{

		auto monster1 = new Monster2(8);
		monster1->setPosition(Vec2(200, 220));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(7);
		monster2->setPosition(Vec2(500, 180));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(3);
		monster3->setPosition(Vec2(300, 250));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(1);
		monster5->setPosition(Vec2(400, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(1150, 430));
		this->addChild(totem);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 11)
	{

		auto monster1 = new Monster2(2);
		monster1->setPosition(Vec2(400, 180));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(4);
		monster2->setPosition(Vec2(500, 280));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(6);
		monster3->setPosition(Vec2(200, 180));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(8);
		monster5->setPosition(Vec2(300, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(1150, 430));
		this->addChild(totem);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == 12)
	{

		auto monster1 = new Monster2(2);
		monster1->setPosition(Vec2(300, 180));
		this->addChild(monster1, 1);
		auto monster2 = new Monster2(5);
		monster2->setPosition(Vec2(400, 280));
		this->addChild(monster2, 1);
		auto monster3 = new Monster2(7);
		monster3->setPosition(Vec2(500, 180));
		this->addChild(monster3, 1);
		auto monster5 = new Monster2(3);
		monster5->setPosition(Vec2(700, 200));
		this->addChild(monster5, 1);


		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);
		this->createMonster(monster2);
		this->createMonster(monster3);
		this->createMonster(monster5);
		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

		auto totem = Sprite::create("structure/Totem.png");
		totem->setPosition(Vec2(1150, 430));
		this->addChild(totem);

		initComplete = true;
		log("init %d", stageNum);
	}
	else if (stageNum == BOSS_MAP_NUM2)
	{

		auto monster1 = new Monster2(12);
		monster1->setPosition(Vec2(winsize.width / 2, winsize.height / 2));
		this->addChild(monster1, 1);



		if (this->createWorld(true))
		{
			this->schedule(schedule_selector(Stage2::tick));
			myContactListener = new ContactListener(player);

			_world->SetContactListener((b2ContactListener*)myContactListener);
		}

		//�ٵ� ����
		this->createMonster(monster1);

		this->createPlayer(player);

		this->createBackground();   //��� �̹��� ����
		this->runAction(Follow::create(player, Rect(0, 0, 1500, 720)));  //ī�޶� �̵�

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

bool Stage2::createWorld(bool debug)
{
	//���� ���� ����

	b2Vec2 gravity = b2Vec2(0.0f, .0f);

	//���带 �����Ѵ�.
	_world = new b2World(gravity);

	//�޽� ������ �� ���Ե� �ٵ���� ���߰�(sleep)�� ������ �����Ѵ�
	_world->SetAllowSleeping(true);

	//�������� �����ۿ��� �� ������ �����Ѵ�. :�׽�Ʈ
	_world->SetContinuousPhysics(true);


	if (debug)
	{
		//���� : ���� ���� ��� �ϴ� ��
		//ȸ�� : ���� ���� ����� ���� ��
		m_debugDraw = new GLESDebugDraw(PTM_RATIO);
		_world->SetDebugDraw(m_debugDraw);

		uint32 flags = 0;

		flags += b2Draw::e_shapeBit;

		m_debugDraw->SetFlags(flags);
	}




	//�����ڸ�(�׵θ�)�� ������ ����(Ground Box)�� �����.

	//�ٵ����� ��ǥ�� �����Ѵ�.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);

	//���忡 �ٵ����� ����(��ǥ)�� �ٵ� �����.
	b2Body *groundBody = _world->CreateBody(&groundBodyDef);

	//���� �ڸ�(�׵θ�) ��輱�� �׸��� �ִ� ����� ��ü�� �����.

	b2EdgeShape groundEdge;
	b2FixtureDef boxShapeDef;
	boxShapeDef.shape = &groundEdge;
	boxShapeDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	boxShapeDef.filter.categoryBits = CATEGORY_GROUND;
	boxShapeDef.filter.maskBits = CATEGORY_MONSTER + CATEGORY_PLAYER;

	//���� ����� ��ü�� Set(��1, ��2)���� �����.
	//�׸��� �ٵ�(groundBody)�� ���(groundEdge)�� ������Ų��.

	//���� �����
	groundEdge.Set(b2Vec2(0, 240 / PTM_RATIO), b2Vec2(200 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//����
	groundEdge.Set(b2Vec2(0, 100 / PTM_RATIO), b2Vec2(0, 240 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//�Ʒ���
	groundEdge.Set(b2Vec2(0, 100 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 100 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//����1
	groundEdge.Set(b2Vec2(200 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(400 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	if (stageNum != BOSS_MAP_NUM2 && this->prev == nullptr) //���ʹ��� nullptr��
	{
		groundEdge.Set(b2Vec2(400 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(500 / PTM_RATIO, 540 / PTM_RATIO));
		groundBody->CreateFixture(&boxShapeDef);

	}

	//����2
	groundEdge.Set(b2Vec2(500 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1000 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	if (stageNum != BOSS_MAP_NUM2 && this->next == nullptr) //�����ʹ��� nullptr��
	{
		groundEdge.Set(b2Vec2(1000 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1100 / PTM_RATIO, 540 / PTM_RATIO));
		groundBody->CreateFixture(&boxShapeDef);

	}


	//����3
	groundEdge.Set(b2Vec2(1100 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1300 / PTM_RATIO, 540 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//������ �����
	groundEdge.Set(b2Vec2(1300 / PTM_RATIO, 540 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 240 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//������
	groundEdge.Set(b2Vec2(1500 / PTM_RATIO, 240 / PTM_RATIO), b2Vec2(1500 / PTM_RATIO, 100 / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	//���� ���� ��-----------------------















	return true;
}

void Stage2::createPlayer(Sprite * player)
{

	//--------------�÷��̾� �ٵ����
	b2BodyDef playerBodyDef;
	playerBodyDef.type = b2_dynamicBody;
	playerBodyDef.position.Set(player->getPosition().x / PTM_RATIO, player->getPosition().y / PTM_RATIO);
	playerBodyDef.linearDamping = 20;
	playerBodyDef.userData = player;


	playerBody = _world->CreateBody(&playerBodyDef);
	playerBody->SetFixedRotation(true);
	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);

	b2PolygonShape playerPolygon;
	playerPolygon.SetAsBox((player->getContentSize().width / 6) / PTM_RATIO, (player->getContentSize().height / 2) / PTM_RATIO);

	b2FixtureDef playerFixtureDef;
	playerFixtureDef.shape = &playerPolygon;
	playerFixtureDef.density = 0.1f;
	playerFixtureDef.restitution = 1;
	playerFixtureDef.filter.groupIndex = GROUP_INDEX_PLAYER;
	playerFixtureDef.filter.categoryBits = CATEGORY_PLAYER;
	playerFixtureDef.filter.maskBits = CATEGORY_MONSTER;
	playerBody->CreateFixture(&playerFixtureDef);

}

void Stage2::createMonster(Sprite * monster)
{
	//--------------�÷��̾� �ٵ����
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
	monsterFixtureDef.density = 0.5f;
	monsterFixtureDef.restitution = 1;

	monsterFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	monsterFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	monsterFixtureDef.filter.maskBits = CATEGORY_PLAYER + CATEGORY_GROUND;

	monsterBody->SetFixedRotation(true);
	monsterBody->CreateFixture(&monsterFixtureDef);
	monsterBodyVector.push_back(monsterBody);
	auto mon = (Monster2*)monster;
	mon->IdleAction();
}

void Stage2::createBackground()
{
	if (stageNum == BOSS_MAP_NUM2)
	{
		auto bg = Sprite::create("stage/stage-boss.png");
		bg->setAnchorPoint(Vec2(0, 0));
		bg->setPosition(Vec2(0, 100));
		this->addChild(bg, 0);
	}
	else
	{
		auto bg = Sprite::create("stage/stage-2.png");
		bg->setAnchorPoint(Vec2(0, 0));
		bg->setPosition(Vec2(0, 100));
		this->addChild(bg, 0);

	}

	if (stageNum != BOSS_MAP_NUM2 && this->prev == nullptr) //���ʹ��� nullptr��
	{

	}
	else if (this->stageNum == BOSS_MAP_NUM2)
	{

		auto door1 = Sprite::create("structure/door.png");
		door1->setAnchorPoint(Vec2(0, 0));
		door1->setPosition(Vec2(380, 390));
		this->addChild(door1, 0);

	}
	else
	{
		if (this->prev->stageNum == BOSS_MAP_NUM2) //�������� �������� ���
		{
			auto door1 = Sprite::create("structure/bossdoor.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(380, 390));
			this->addChild(door1, 0);

			auto bossEye = Sprite::create("structure/bosseyes.png");
			bossEye->setPosition(Vec2(door1->getContentSize().width / 2, door1->getContentSize().height / 2 + 30));
			door1->addChild(bossEye);

			auto seq = Sequence::create(FadeOut::create(0.5), FadeIn::create(0.5), DelayTime::create(1), nullptr);
			auto seqR = RepeatForever::create(seq);
			bossEye->runAction(seqR);
		}
		else if (this->prev->stageNum == ITEM_MAP_NUM) //������ �����Ͻ�
		{
			auto door1 = Sprite::create("structure/itemdoor.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(380, 390));
			this->addChild(door1, 0);
		}
		else
		{
			auto door1 = Sprite::create("structure/door.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(380, 390));
			this->addChild(door1, 0);
		}
	}

	if (stageNum != BOSS_MAP_NUM2 && this->next == nullptr) //�����ʹ��� nullptr��
	{

	}
	else if (this->stageNum == BOSS_MAP_NUM2)
	{

		auto door1 = Sprite::create("structure/door.png");
		door1->setAnchorPoint(Vec2(0, 0));
		door1->setPosition(Vec2(985, 390));
		this->addChild(door1, 0);

	}
	else
	{
		if (this->next->stageNum == BOSS_MAP_NUM2)
		{
			auto door1 = Sprite::create("structure/bossdoor.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(985, 390));
			this->addChild(door1, 0);

			auto bossEye = Sprite::create("structure/bosseyes.png");
			bossEye->setPosition(Vec2(door1->getContentSize().width / 2, door1->getContentSize().height / 2 + 30));
			door1->addChild(bossEye);

			auto seq = Sequence::create(FadeOut::create(0.5), FadeIn::create(0.5), DelayTime::create(1), nullptr);
			auto seqR = RepeatForever::create(seq);
			bossEye->runAction(seqR);
		}
		else if (this->next->stageNum == ITEM_MAP_NUM) //������ �����Ͻ�
		{
			auto door1 = Sprite::create("structure/itemdoor.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(985, 390));
			this->addChild(door1, 0);
		}
		else
		{
			auto door1 = Sprite::create("structure/door.png");
			door1->setAnchorPoint(Vec2(0, 0));
			door1->setPosition(Vec2(985, 390));
			this->addChild(door1, 0);
		}

	}

	if (stageNum != BOSS_MAP_NUM2 && this->prev == nullptr) //���ʹ��� nullptr��
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




	if (stageNum != BOSS_MAP_NUM2 && this->next == nullptr) //�����ʹ��� nullptr��
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

	if (stageNum == 0 || stageNum == ITEM_MAP_NUM)
	{
		log("make");
		this->MakeItem();
	}

}

void Stage2::MakeItem()
{
	int num;
	/*while (1)
	{
		num = rand() % 15 + 1;
		if (player->getItem[num] == 1)
		{
			continue;
		}
		else
		{
			player->getItem[num] = 1;
			break;
		}
	}*/
	num = 9;
	auto item = new Item(num);
	this->addChild(item, 1);
	item->setPosition(Vec2(1500 / 2, winsize.height / 2));

	//--------------�÷��̾� �ٵ����
	b2BodyDef itemBodyDef;
	itemBodyDef.type = b2_kinematicBody;
	itemBodyDef.position.Set(item->getPosition().x / PTM_RATIO, item->getPosition().y / PTM_RATIO);
	itemBodyDef.userData = item;


	auto itemBody = _world->CreateBody(&itemBodyDef);

	//playerBody->SetMassData(mass);
	//playerBody->SetGravityScale(0);

	b2PolygonShape itemPolygon;
	itemPolygon.SetAsBox((item->getContentSize().width / 2) / PTM_RATIO, (item->getContentSize().height / 2) / PTM_RATIO);
	//log(" %f ", (monster->getContentSize().height / 2.5));

	b2FixtureDef ItemFixtureDef;
	ItemFixtureDef.shape = &itemPolygon;
	ItemFixtureDef.density = 0.5f;
	ItemFixtureDef.restitution = 1;

	ItemFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	ItemFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	ItemFixtureDef.filter.maskBits = CATEGORY_PLAYER + CATEGORY_GROUND;

	itemBody->SetFixedRotation(true);
	itemBody->CreateFixture(&ItemFixtureDef);
	itemBodyVector.push_back(itemBody);

}

Stage2::~Stage2()
{
	delete _world;
	_world = nullptr;


}


void Stage2::onEnter()
{
	Layer::onEnter();

}
//void Stage2::onExit()
//{
//	SimpleAudioEngine::getInstance()->end();
//	Layer::onExit();
//}
//
//void Stage2::onExit()
//{
//	_eventDispatcher->removeAllEventListeners();
//	Layer::onExit();
//}


void Stage2::draw(Renderer * renderer, const Mat4 & transform, uint32_t flags)
{
	//Layer::draw();
	Layer::draw(renderer, transform, flags);
GL:ccGLEnableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION);

	kmGLPushMatrix();
	_world->DrawDebugData();
	kmGLPopMatrix();


}

void Stage2::tick(float dt)
{
	//������ ��ġ�� �̿��� �׷��� ��ġ�� �����Ѵ�.

	//velocityIterations : �ٵ���� ���������� �̵���Ű�� ���� �ʿ��� �浹����
	//�ݺ������� ���
	//positionIterations : ����Ʈ �и��� ��ħ ������ ���̱� ���� �ٵ��� ��ġ��
	//�ݺ������� ����
	//���� Ŭ���� ��Ȯ�� ������ ���������� ������ ��������.

	//�޴��� ���� ���尪
	int velocityIterations = 8;
	int positionIterations = 4;

	//Step : ���� ���踦 �ùķ��̼��Ѵ�.
	_world->Step(dt, velocityIterations, positionIterations);
	//��� ���� ��ü���� ��ũ�� ����Ʈ�� ����Ǿ� ������ ���� �ְ� ������ �ִ�.
	//������� ��ü��ŭ ������ �����鼭 �ٵ� ���� ��������Ʈ�� ���⼭ �����Ѵ�.
	for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			Sprite *spriteData = (Sprite*)b->GetUserData();
			spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO));
			spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));

			if (b->GetUserData() == player &&  player->alive)
			{
				float vx = joystickVelocity1->x * player->speed;//���ǵ�
				float vy = joystickVelocity1->y * player->speed;
				//set ball velocity by Joystick
				b->SetLinearVelocity(b2Vec2(vx, vy) + (b->GetLinearVelocity()));

			}


		}


	}


	//------------------------------------------------------�̻��� �ٵ� ������ ���Ϳ����� �ٵ� ����
	for (int i = 0; i < missileBodyVector.size(); i++)
	{

		if (missileBodyVector[i]->GetUserData() == nullptr)
		{
			_world->DestroyBody(missileBodyVector[i]);
			missileBodyVector.erase(missileBodyVector.begin() + i);

		}


	}


	for (int i = 0; i < monsterMissileBodyVector.size(); i++)
	{

		if (monsterMissileBodyVector[i]->GetUserData() == nullptr)
		{
			_world->DestroyBody(monsterMissileBodyVector[i]);
			monsterMissileBodyVector.erase(monsterMissileBodyVector.begin() + i);

		}


	}



	//------------------------------------------------------- ���� �ٵ� ����
	for (int i = 0; i < monsterBodyVector.size(); i++)
	{

		if (monsterBodyVector[i]->GetUserData() == nullptr)
		{


			_world->DestroyBody(monsterBodyVector[i]);


			monsterBodyVector.erase(monsterBodyVector.begin() + i);
		}

	}


	//------------------------------------------------------------------ �� ����
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

		player->nowMagic += 2;
		if (player->nowMagic > 10)
			player->nowMagic = 10;
		player->magicEnergy->setTexture2(player->nowMagic);
		doorOpen = true;
	}



	//-------------------------------------------------------------- ZOrder ó��
	for (int i = 0; i < monsterBodyVector.size(); i++)
	{

		Monster2 *monster = (Monster2*)(monsterBodyVector[i]->GetUserData());
		if (monster != nullptr)
		{
			//  �浹 ó��
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
	}


	//----------------Item ZOder
	for (int i = 0; i < itemBodyVector.size(); i++)
	{

		Item *item = (Item*)(itemBodyVector[i]->GetUserData());

		//  �浹 ó��
		if (player->getPosition().y < item->getPosition().y + 50 && player->getPosition().y > item->getPosition().y - 10)
		{
			//log("dddd");
			b2Filter newFilter;
			b2Filter oldFilter;
			oldFilter.categoryBits = 0x0001;
			oldFilter.maskBits = 0xFFFF;
			oldFilter.groupIndex = 0;
			oldFilter = itemBodyVector.at(i)->GetFixtureList()->GetFilterData();
			newFilter = oldFilter;
			newFilter.maskBits = CATEGORY_PLAYER;
			itemBodyVector.at(i)->GetFixtureList()->SetFilterData(newFilter);
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
			oldFilter = itemBodyVector.at(i)->GetFixtureList()->GetFilterData();
			newFilter = oldFilter;
			newFilter.maskBits = 0;////////////////////////////////
			itemBodyVector.at(i)->GetFixtureList()->SetFilterData(newFilter);
			//CC_SAFE_DELETE(newFilter);
			//CC_SAFE_DELETE(oldFilter);

		}


		if (player->getPosition().y > item->getPosition().y + 50)
			player->setZOrder(item->getZOrder() - 1);
		else if (player->getPosition().y < item->getPosition().y + 10)
			player->setZOrder(item->getZOrder() + 1);



	}


	//------------------------------------------------------------------- ���� ó��
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

	//------------------------------------------------------------------ ���� �̵�



	//------------------------------------------------------------------ ĳ���� �̵�
	if (player->alive)
	{
		// ĳ���� �̵� ���� �κ�
		if (joystickVelocity1->x == 0 && joystickVelocity1->y == 0 && isMoving == false)
		{

			//player->stopAllActions();
			player->IdleAction();
			isMoving = true;

		}
		else if (joystickVelocity1->x < 0)
		{
			//log("%f", joystick1->getVelocity().x);
			if (isMoving == true)
			{
				//player->stopAllActions();
				player->MoveAction();
				isMoving = false;
			}
			player->setFlippedX(true);
			player->ChildFlip(true);

		}
		else if (joystickVelocity1->x > 0)
		{
			//log("%f", joystick1->getVelocity().x);
			if (isMoving == true)
			{
				//player->stopAllActions();
				player->MoveAction();
				isMoving = false;
			}
			player->setFlippedX(false);
			player->ChildFlip(false);

		}
	}

	//------------------------------------------------------------------ ���ΰ� ����

	if (player->alive == false)
	{
		this->scheduleOnce(schedule_selector(Stage2::LoadGameOver), 2);
	}





	//------------------------------------------------------------------  A.I
	if (isAiOn == false)
	{
		this->scheduleOnce(schedule_selector(Stage2::AITick), 1);
		isAiOn = true;
	}


}

void Stage2::LoadGameOver(float dt)
{
	auto pScene = Gameover::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, pScene));

}


void Stage2::BossTick(float dt)
{
	auto playerPosition = player->getPosition();
	/////////////////////////////         ���� �۾� �ʿ�

	for (int i = 0; i < monsterBodyVector.size(); i++)
	{
		if (((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->nowEnergy > ((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->maxEnergy/2)
		{
			if (bossFirstAttack)
			{
				this->BossCrossAttack();
				bossFirstAttack = false;
			}
			else
			{
				this->BossXAttack();
				bossFirstAttack = true;

			}
		}
		else if (((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->nowEnergy <= ((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->maxEnergy/2)
		{
			BossPointAttack(monsterBodyVector.at(i));

		}
	}
}
void Stage2::BossPointAttack(b2Body *bossBody)
{
	BossMissile *missile = new BossMissile(1);
	missile->setPosition(((Monster2*)(bossBody->GetUserData()))->getPosition());
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
	missileBody->SetLinearVelocity(playerBody->GetPosition() - bossBody->GetPosition());
	//missileBody->SetTransform(b2Vec2(player->getPosition().x / PTM_RATIO, player->getPosition().y / PTM_RATIO), 0);
	monsterMissileBodyVector.push_back(missileBody);
}
void Stage2::BossCrossAttack()
{
	for (int i = 0; i < monsterBodyVector.size(); i++)
	{
		this->MakeBossMissile1(1, 0, 7);
		this->MakeBossMissile1(3, 7, 0);
		this->MakeBossMissile1(5, 0, -7);
		this->MakeBossMissile1(7, -7, 0);
	}

}
void Stage2::BossXAttack()
{
	for (int i = 0; i < monsterBodyVector.size(); i++)
	{

		this->MakeBossMissile1(2, 4, 4);
		this->MakeBossMissile1(4, 4, -4);
		this->MakeBossMissile1(6, -4, -4);
		this->MakeBossMissile1(8, -4, 4);
	}
}

void Stage2::AITick(float dt)  //  AI ����
{
	if (stageNum == BOSS_MAP_NUM2)
	{
		this->schedule(schedule_selector(Stage2::BossTick), 1);
	}

	this->schedule(schedule_selector(Stage2::AITick2));


}
void Stage2::AITick2(float dt)  // ���� �̵� �κ�
{
	auto playerPosition = player->getPosition();

	for (int i = 0; i < monsterBodyVector.size(); i++)
	{
		if (((Monster2*)(monsterBodyVector.at(i)->GetUserData())) != nullptr)
		{
			if (((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->isMove == false)
			{
				((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->MoveAction();
				((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->isMove = true;
			}
			auto x = playerBody->GetPosition().x - monsterBodyVector.at(i)->GetPosition().x;
			auto y = playerBody->GetPosition().y - monsterBodyVector.at(i)->GetPosition().y;
			float xR, yR;
			if (stageNum == BOSS_MAP_NUM2)
			{
				if (x < 0)
					xR = -2;
				else
					xR = 2;

				if (y < 0)
					yR = -2;
				else
					yR = 2;
			}
			else
			{
				if (x < 0)
					xR = -2;
				else
					xR = 2;

				if (y < 0)
					yR = -2;
				else
					yR = 2;
			}
			if (xR > 0)
				((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->setFlippedX(true);
			else if (xR < 0)
				((Monster2*)(monsterBodyVector.at(i)->GetUserData()))->setFlippedX(false);
			monsterBodyVector.at(i)->SetLinearVelocity(b2Vec2(xR, yR));

		}
	}



}
void Stage2::MakeBossMissile1(int location, float x, float y)
{
	Vec2 position;
	if (location == 1)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y + 50);
	}
	else if (location == 2)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x + 50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y + 50);
	}
	else if (location == 3)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x + 50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y);
	}
	else if (location == 4)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x + 50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y - 50);
	}
	else if (location == 5)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y - 50);
	}
	else if (location == 6)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x - 50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y - 50);
	}
	else if (location == 7)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x - 50
			, ((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().y);
	}
	else if (location == 8)
	{
		position = Vec2(((Sprite*)(monsterBodyVector.at(0)->GetUserData()))->getPosition().x - 50
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



void Stage2::LongAttack(int num)
{
	switch (num)
	{
	case RIGHTLONGATTACK:

		if (!this->isScheduled(schedule_selector(Stage2::RightLongAttack)) &&
			!this->isScheduled(schedule_selector(Stage2::clearTime)))
		{
			this->RightLongAttack(0);
		}
		else if (!this->isScheduled(schedule_selector(Stage2::RightLongAttack)))
			this->scheduleOnce(schedule_selector(Stage2::RightLongAttack), player->attackSpeed);
		break;


	case LEFTLONGATTACK:
		if (!this->isScheduled(schedule_selector(Stage2::LeftLongAttack)) &&
			!this->isScheduled(schedule_selector(Stage2::clearTime)))
		{
			this->LeftLongAttack(0);
		}
		else if (!this->isScheduled(schedule_selector(Stage2::LeftLongAttack)))
			this->scheduleOnce(schedule_selector(Stage2::LeftLongAttack), player->attackSpeed);
		break;
	}
}

void Stage2::RightLongAttack(float dt)
{
	SimpleAudioEngine::getInstance()->playEffect(PLAYER_SWORD);
	SwordMissile *missile = new SwordMissile(player->missileNum);
	missile->setPosition(Vec2(player->getPosition().x + 50.f, player->getPosition().y));
	missile->setFlipX(true);
	missile->setAnchorPoint(Vec2(0.8, 0.5));
	this->addChild(missile);
	player->stopAllActions();
	player->setFlippedX(false);
	player->ChildFlip(false);
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
	missileFixtureDef.density = player->nukBack;
	missileFixtureDef.restitution = 0.5;
	missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	missileFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	missileFixtureDef.filter.maskBits = CATEGORY_MONSTER;
	//missileBody->SetFixedRotation(true);
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(player->missileSpeed, 0));
	missileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
	this->scheduleOnce(schedule_selector(Stage2::clearTime), player->attackSpeed);

}
void Stage2::LeftLongAttack(float dt)
{

	SimpleAudioEngine::getInstance()->playEffect(PLAYER_SWORD);
	SwordMissile *missile = new SwordMissile(player->missileNum);
	missile->setPosition(Vec2(player->getPosition().x - 50.f, player->getPosition().y));
	this->addChild(missile);
	player->stopAllActions();
	player->setFlippedX(true);
	player->ChildFlip(true);
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
	missileFixtureDef.density = player->nukBack;
	missileFixtureDef.restitution = 0.5;
	missileFixtureDef.filter.groupIndex = GROUP_INDEX_MONSTER;
	missileFixtureDef.filter.categoryBits = CATEGORY_MONSTER;
	missileFixtureDef.filter.maskBits = CATEGORY_MONSTER;
	//missileBody->SetFixedRotation(true);
	missileBody->CreateFixture(&missileFixtureDef);
	missileBody->SetLinearVelocity(b2Vec2(-player->missileSpeed, 0));
	missileBodyVector.push_back(missileBody);
	//joystick2->attack = 0;
	this->scheduleOnce(schedule_selector(Stage2::clearTime), player->attackSpeed);

}

void Stage2::clearTime(float dt)
{
}
