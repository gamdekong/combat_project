#include "MenuScene.h"
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

Scene* MenuScene::createScene()
{

	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	auto winSize = Director::getInstance()->getWinSize();

	bg = Sprite::create("menu/bg.png");
	bg->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(bg,0);
	log("dd");
	auto regameButton = MenuItemImage::create("menu/regame_button.png", "menu/regame_button_pressed.png", CC_CALLBACK_1(MenuScene::ReGame, this));
	auto regameMenu = Menu::create(regameButton, nullptr);
	regameButton->setPosition(Vec2(bg->getContentSize().width / 2, bg->getContentSize().height - 150));

	
	auto exitButton = MenuItemImage::create("menu/exit_button.png", "menu/exit_button_pressed.png", CC_CALLBACK_1(MenuScene::ExitGame, this));
	auto exitMenu = Menu::create(exitButton, nullptr);
	exitButton->setPosition(Vec2(bg->getContentSize().width / 2, 150));

	auto exitButton2 = MenuItemImage::create("menu/x_button.png", "menu/x_button_pressed.png", CC_CALLBACK_1(MenuScene::CloseMenu, this));
	auto exitMenu2 = Menu::create(exitButton2, nullptr);
	exitButton2->setPosition(Vec2(bg->getContentSize().width , bg->getContentSize().height));
	
	regameMenu->setPosition(Vec2(0, 0));
	exitMenu->setPosition(Vec2(0, 0));
	exitMenu2->setPosition(Vec2(0, 0));

	bg->addChild(regameMenu, 1);
	bg->addChild(exitMenu, 1);
	bg->addChild(exitMenu2, 1);


	return true;
}

void MenuScene::ReGame(Ref * p)
{
	SimpleAudioEngine::getInstance()->playEffect(CLICK);
	auto reallybar = Sprite::create("menu/really_bar.png");
	auto ok = MenuItemImage::create("menu/ok_button.png", "menu/ok_button_pressed.png", CC_CALLBACK_1(MenuScene::Ok, this));
	auto x = MenuItemImage::create("menu/x_button.png", "menu/x_button_pressed.png", CC_CALLBACK_1(MenuScene::X, this));
	
	auto menu = Menu::create(ok, x, nullptr);
	reallybar->setTag(10);

	menu->setPosition(Vec2(0, 0));
	ok->setPosition(Vec2(100, 0));
	x->setPosition(Vec2(reallybar->getContentSize().width - 100, 0));
	reallybar->addChild(menu);
	bg->addChild(reallybar,5);
	reallybar->setPosition(Vec2(bg->getContentSize().width / 2, bg->getContentSize().height / 2));

}

void MenuScene::ExitGame(Ref * p)
{
	SimpleAudioEngine::getInstance()->playEffect(CLICK);
	auto reallybar = Sprite::create("menu/really_bar.png");
	auto ok = MenuItemImage::create("menu/ok_button.png", "menu/ok_button_pressed.png", CC_CALLBACK_1(MenuScene::Ok2, this));
	auto x = MenuItemImage::create("menu/x_button.png", "menu/x_button_pressed.png", CC_CALLBACK_1(MenuScene::X, this));

	auto menu = Menu::create(ok, x, nullptr);
	reallybar->setTag(10);

	menu->setPosition(Vec2(0, 0));
	ok->setPosition(Vec2(100, 0));
	x->setPosition(Vec2(reallybar->getContentSize().width - 100, 0));
	reallybar->addChild(menu);
	bg->addChild(reallybar, 5);
	reallybar->setPosition(Vec2(bg->getContentSize().width / 2, bg->getContentSize().height / 2));
}

void MenuScene::CloseMenu(Ref * p)
{
	SimpleAudioEngine::getInstance()->playEffect(CLICK);
	Director::getInstance()->resume();
	this->removeFromParentAndCleanup(true);
}

void MenuScene::Ok(Ref * p)
{
	SimpleAudioEngine::getInstance()->playEffect(CLICK);
	Director::getInstance()->resume();
	auto pScene = Gameover::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, pScene));
}

void MenuScene::Ok2(Ref * p)
{
	SimpleAudioEngine::getInstance()->playEffect(CLICK);
	Director::sharedDirector()->end();
}

void MenuScene::X(Ref * p)
{
	SimpleAudioEngine::getInstance()->playEffect(CLICK);
	bg->removeChildByTag(10);
}
