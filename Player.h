#pragma once
#include "cocos2d.h"
#include "SwordMissile.h"
#include "Energy.h"
//#include "Stage1.h"
using namespace cocos2d;


class Player : public cocos2d::Sprite
{
public:
	void IdleAction();
	void AttackAction();
	void DeadAction();
	void MoveAction();
	void HittedAction();
	void ChangeHitted(float dt);
	void ChangeHitting(float dt);
	void hittedAction2(float dt);
	void Delay();


	Player();
	void init2();
	Energy *energy;
	Layer *nowStage;
	float nowEnergy;
	
	int count = 100;
	int hitCount = 0;

	float speed;           //2.5 ~ 4
	float attackSpeed;    //0.1 ~ 0.5
	float nukBack ;      // 0.5 ~ 10
	float power;        // 1 ~ 5
	float missileSpeed;  // 10 ~ 20

	bool alive = true;
	bool hitted = false;
	bool hitting = true;
	SwordMissile *missile;
	Texture2D *playerMoveTexture;
	Texture2D *playerAttackTexture;
	Texture2D *playerIdleTexture;
	Texture2D *playerDeadTexture;



};