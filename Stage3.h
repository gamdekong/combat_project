#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "Player.h"
#include "Monster3.h"
#include "SwordMissile.h"
#include "ContactListener.h"
#include "BossMissile.h"
#include "Item.h"



#define PTM_RATIO 32
#define GROUP_INDEX_PLAYER -10
#define GROUP_INDEX_MONSTER 10
#define RIGHTLONGATTACK 100
#define LEFTLONGATTACK 200


#define CATEGORY_PLAYER 0x0005
#define CATEGORY_MONSTER 0x0002
#define CATEGORY_GROUND 0x0003
#define CATEGORY_MISSILE 0x0004

#define ITEM_MAP_NUM 8
#define BOSS_MAP_NUM3 15

using namespace cocos2d;
using namespace std;

class Stage3 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Stage3);

	~Stage3();
	void onEnter();
	//void onExit();
	void tick(float dt);
	void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);

	int stageNum;
	Stage3 *prev = nullptr;
	Stage3 *next = nullptr;

	bool createWorld(bool);
	void createPlayer(Sprite *player);
	void createMonster(Sprite *monster);
	void createBackground();
	void LongAttack(int num);
	void RightLongAttack(float dt);
	void LeftLongAttack(float dt);
	void clearTime(float dt);
	void AITick(float dt);
	void AITick2(float dt);
	void MakeBossMissile1(int, float, float);
	void BossTick(float dt);
	void BossCrossAttack();
	void BossXAttack();
	void BossPointAttack(b2Body*);
	void MakeItem();
	void LoadGameOver(float dt);

	b2World *_world;
	Size winsize;
	Vec2 *joystickVelocity1, *joystickVelocity2;
	bool *joystickIspressed1, *joystickIspressed2;
	Player *player;
	b2Body *playerBody;
	b2Body *leftLockBody, *rightLockBody;
	vector<b2Body*> missileBodyVector;
	vector<b2Body*> monsterMissileBodyVector;
	vector<b2Body*> monsterBodyVector;
	vector<b2Body*> doorBodyVector;
	vector<b2Body*> itemBodyVector;
	ContactListener* myContactListener;
	int clickCount = 0;
	bool isMoving = false;
	bool isAttacking;
	bool initComplete = false;
	bool doorOpen = false;
	bool isAiOn = false;
	bool bossFirstAttack = true;
	bool scheduleB = true;




	//for debugging
	GLESDebugDraw *m_debugDraw;
};
