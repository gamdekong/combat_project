#ifndef __Stage1_SCENE_H__
#define __Stage1_SCENE_H__


#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "Player.h"
#include "Monster.h"
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
#define BOSS_MAP_NUM 9

using namespace cocos2d;
using namespace std;

class Stage1 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Stage1);
	
	~Stage1();
	void onEnter();
	//void onExit();
	void tick(float dt);
	void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);

	int stageNum;
	Stage1 *prev = nullptr;
	Stage1 *next = nullptr;
	
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
	int count = 0;
	bool isAttacking;
	bool initComplete = false;
	bool doorOpen = false;
	bool isAiOn = false;
	bool bossFirstAttack = true;
	



	//for debugging
	GLESDebugDraw *m_debugDraw;
};

#endif // __BackgroundLayer_SCENE_H__
