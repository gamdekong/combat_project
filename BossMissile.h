#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class BossMissile : public cocos2d::Sprite
{
public:
	BossMissile(int);
	void init2(int);
	void startAction();

	int missileNum;

	Texture2D *missile;
	Sprite *missile1;
	Sprite *missile2;
	Sprite *missile3;
	Sprite *missile4;
	Sprite *missile5;


};