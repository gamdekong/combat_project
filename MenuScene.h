#pragma once

#include "cocos2d.h"
#include "Gameover.h"


using namespace cocos2d;



class MenuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MenuScene);

	void ReGame(Ref* p);
	void ExitGame(Ref *p);
	void CloseMenu(Ref *p);
	void Ok(Ref *p);
	void Ok2(Ref *p);
	void X(Ref *p);

	Sprite *bg;


	//void onEnter();

};

