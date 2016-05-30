#include "Intro.h"
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

Scene* Intro::createScene()
{

	auto scene = Scene::create();
	auto layer = Intro::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Intro::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	srand((unsigned)time(NULL));

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(INTRO_BGM);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(LOBBY_BGM);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(STAGE2_BGM);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(STAGE1_BGM);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(STAGE3_BGM);

	SimpleAudioEngine::getInstance()->preloadEffect(PLAYER_SWORD);
	SimpleAudioEngine::getInstance()->preloadEffect(PLAYER_HITTED);
	SimpleAudioEngine::getInstance()->preloadEffect(CLICK);
	SimpleAudioEngine::getInstance()->preloadEffect(ITEM_GET);
	SimpleAudioEngine::getInstance()->preloadEffect(ITEM_USE);

	SimpleAudioEngine::getInstance()->playBackgroundMusic(INTRO_BGM, true);


	auto winsize = Director::getInstance()->getWinSize();

	auto bg = Sprite::create("intro/intro_bg.png");
	bg->setPosition(Vec2(0 , 0));
	bg->setAnchorPoint(Vec2(0, 0));

	auto title = Sprite::create("intro/title.png");
	title->setPosition(Vec2(winsize.width / 2, winsize.height/2 + 200));

	auto sub_title = Sprite::create("intro/sub_title.png");
	sub_title->setPosition(Vec2(title->getContentSize().width-100, -30));
	
	
	

	
	

	auto clickbg = Sprite::create("intro/clickbg.png");
	clickbg->setOpacity(200);
	clickbg->setPosition(Vec2(winsize.width / 2, 100));
	
	auto click = Sprite::create("intro/click.png");
	click->setPosition(Vec2(clickbg->getContentSize().width / 2, clickbg->getContentSize().height / 2));
	
	
	this->addChild(bg,0);
	this->addChild(title, 10);
	title->addChild(sub_title);
	this->addChild(clickbg,10);
	clickbg->addChild(click);

	//this->addChild(bg2, 4);
	auto seq = Sequence::create(FadeOut::create(0.2),FadeIn::create(0.2), DelayTime::create(0.5), nullptr);
	auto seqR = RepeatForever::create(seq);
	click->runAction(seqR);


	

	this->schedule(schedule_selector(Intro::tick));
	
	/*auto fi = FadeIn::create(5);
	auto fo = FadeOut::create(5);
	auto move1 = MoveBy::create(20,(Vec2(100, 0)));
	auto seq = Sequence::create(fi, fo, nullptr);
	auto spawn1 = Spawn::create(seq, move1, nullptr);
	auto r1 = RepeatForever::create(spawn1);


	auto fi1 = FadeIn::create(3);
	auto fo1 = FadeOut::create(3);
	auto move2 = MoveBy::create(20, (Vec2(-100, 0)));
	auto seq2 = Sequence::create(fi1, fo1, nullptr);
	auto spawn2 = Spawn::create(seq2, move2, nullptr);
	auto r2 = RepeatForever::create(spawn2);


	orora->runAction(r1);
	orora2->runAction(r2);*/
	//orora2->runAction(moveRight);

	return true;
}

void Intro::doParticles()
{

	int x = rand() % 1200 - 200 ;
	int y = rand() % 700 + 300;
	int type = rand() % 2 + 1;
	int speed = rand() % 3+6 ;
	speed = speed / 3;
	float size = (float)(rand() % 3+7 ) / 10;
	
	auto shooting = Sprite::create("intro/shooting_star.png");


		
		if (shooting != nullptr)
		{

			//파티클의 크기 조정
			shooting->setScale(size);

			//파티클의 지속 시간 조정 : -1 means 'foerver'
			//particleTest->setDuration(1,0);

			//파티클의 위치 조정
			shooting->setPosition(Vec2(x, y));
			auto move = MoveBy::create(speed, Vec2(2000, -1500));
			auto seq = Sequence::create(move, RemoveSelf::create(), nullptr);
			shooting->runAction(seq);
			this->addChild(shooting,5);

		}
	
	

}

void Intro::doStar()
{
	int x = rand() % 1280 + 1;
	int y = rand() % 720 + 1;
	float size = (float)(rand() % 3 + 5) / 10;

	auto star = Sprite::create("intro/star.png");
	star->setPosition(Vec2(x, y));
	star->setOpacity(0);
	star->setScale(size);
	this->addChild(star,3);

	auto starFadein = FadeIn::create(1);
	auto starFadeout = FadeOut::create(1);
	auto rotate = RotateBy::create(2, 360);
	auto fade = Sequence::create(starFadein,starFadeout, nullptr);
	
	auto spawnAction = Spawn::create(fade, rotate, nullptr);
	auto seq = Sequence::create(spawnAction, RemoveSelf::create(), nullptr);
	
	star->runAction(seq);
}

void Intro::tick(float dt)
{
	


	int time = rand() % 100 + 1;
	if (time < 3)
	{
		this->doParticles();
	}
	if (time > 80)
	{
		this->doStar();
	}

	
}


void Intro::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Intro::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(Intro::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(Intro::onTouchesEnded, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Intro::onExit()
{
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	SimpleAudioEngine::getInstance()->end();
	Layer::onExit();

}

void Intro::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{


}

void Intro::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
	



	

}

void Intro::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
	auto pScene = LobbyLayer::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5, pScene));

}