#pragma once
#include "cocos2d.h"
using namespace cocos2d;


class Item : public cocos2d::Sprite
{
public:


	Item(int);
	void init2();
	void addItem();
	void setTexture2(int);
	
	Texture2D *texture;
	int itemNum;
	int power;
	float attackSpeed;
	float nukBack;

	Texture2D *activeItem1;
	Texture2D *activeItem2;
	Texture2D *activeItem3;
	Texture2D *activeItem4;


};