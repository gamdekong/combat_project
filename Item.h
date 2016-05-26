#pragma once
#include "cocos2d.h"
using namespace cocos2d;


class Item : public cocos2d::Sprite
{
public:


	Item(int);
	void init2();
	void addItem();
	
	Texture2D *texture;
	int itemNum;
	int power;
	float attackSpeed;
	float nukBack;


};