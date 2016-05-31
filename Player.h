#pragma once
#include "cocos2d.h"
#include "SwordMissile.h"
#include "Energy.h"
#include "magic.h"
//#include "Stage1.h"
using namespace cocos2d;


class Player : public cocos2d::Sprite
{
public:
	void IdleAction();
	void AttackAction(bool);
	void DeadAction();
	void MoveAction();
	void HittedAction();
	void ChangeHitted(float dt);
	void ChangeHitting(float dt);
	void hittedAction2(float dt);
	void ItemImaging(float dt);
	void Delay();
	void ChildFlip(bool);


	Player();
	void init2();
	Energy *energy;
	magic *magicEnergy;
	Layer *nowStage;
	
	int activeItem;
	int count = 100;
	int hitCount = 0;

	float nowMagic;
	float nowEnergy;
	float speed;           //2.5 ~ 4
	float attackSpeed;    //0.1 ~ 0.7
	float nukBack ;      // 0.5 ~ 10
	float power;        // 1 ~ 5
	float missileSpeed;  // 5 ~ 20
	int missileNum;

	int itemImage[16] = { 0 };
	int getItem[16] = { 0 };

	bool alive = true;
	bool hitted = false;
	bool hitting = true;
	//SwordMissile *missile;
	Texture2D *playerMoveTexture;
	Texture2D *playerAttackTexture;
	Texture2D *playerIdleTexture;
	Texture2D *playerDeadTexture;

	Sprite *getcigar;
	Sprite *getcross;
	Sprite *getdumbel;
	Sprite *getgamdekong;
	Sprite *getgarlic;
	Sprite *getpensil;
	Sprite *getpipe;
	Sprite *getblue;
	Sprite *getred;
	Sprite *getyellow;




};