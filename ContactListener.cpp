#include "ContactListener.h"
#include "SwordMissile.h"
#include "Monster.h"
#include "BossMissile.h"
#include "Item.h"
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

ContactListener::ContactListener(Player *player) {
	this->player = player;
}

ContactListener::~ContactListener() {
}

void ContactListener::BeginContact(b2Contact *contact)
{
	
	//CCLog("Contact:Begin");

	b2Fixture *fixA = contact->GetFixtureA();
	b2Fixture *fixB = contact->GetFixtureB();

	b2Body *bodyA = fixA->GetBody();
	b2Body *bodyB = fixB->GetBody();

	auto spriteA = (Sprite*)bodyA->GetUserData();
	auto spriteB = (Sprite*)bodyB->GetUserData();


	if ( (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_kinematicBody) ||
		(bodyB->GetType() == b2_dynamicBody && bodyA->GetType() == b2_kinematicBody) )
	{
		if (spriteA != nullptr && spriteB != nullptr)
		{
			if (spriteA->getTag() == 1 && spriteB->getTag() == 5) // A가 플레이어 B가 아이템일 경우
			{
				Item *item = (Item*)spriteB;
				if (item->itemNum == 1)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					int temp = player->activeItem;

					player->activeItem = 1;
					item->itemNum = temp;
					item->removeAllChildren();
					item->addItem();
				}
				else if (item->itemNum == 2)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					int temp = player->activeItem;

					player->activeItem = 2;
					item->itemNum = temp;
					item->removeAllChildren();
					item->addItem();
				}
				else if (item->itemNum == 3)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					int temp = player->activeItem;

					player->activeItem = 3;
					item->itemNum = temp;
					item->removeAllChildren();
					item->addItem();
				}
				else if (item->itemNum == 4)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					int temp = player->activeItem;

					player->activeItem = 4;
					item->itemNum = temp;
					item->removeAllChildren();
					item->addItem();
				}
				else if (item->itemNum == 5)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 2;
					if(player->power < 1)
						player->power = 1;
					else if(player->power > 5)
						player->power = 5;
					
					player->attackSpeed += -0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += 0.5;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += 5;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 2;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;
					
					player->missileNum = 5;


					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 6)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 2;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += 0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += -1.5;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += 2;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 1;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->nowEnergy += -2;
					player->energy->setTexture2(player->nowEnergy);

					player->itemImage[6] = 1;


					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 7)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 1;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;


					player->speed += -0.5;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += 5;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					

					player->nowEnergy += 3;
					player->energy->setTexture2(player->nowEnergy);

					player->itemImage[7] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 8)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 4;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += 0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += -1;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += -5;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 5;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->nowEnergy += 1;
					player->energy->setTexture2(player->nowEnergy);

					player->itemImage[8] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 9)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 5;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += -0.2;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += 1;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += 10;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 1;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->missileNum = 4;
					player->itemImage[9] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 10)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);

					player->attackSpeed += -0.2;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += 1;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += -5;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->itemImage[10] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 11)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += -1;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += -0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += 1;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += -3;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->itemImage[11] = 1;
					


					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 12)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 3;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += 0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;


					player->missileSpeed += 3;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 5;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->missileNum = 2;
					player->itemImage[12] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 13)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->speed += 2;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;


					player->itemImage[13] = 1;
					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 14)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 2;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;


					player->itemImage[14] = 1;
					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 15)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);

					player->attackSpeed += -0.2;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->missileNum = 3;
					player->itemImage[15] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}

			}
			else if (spriteB->getTag() == 1 && spriteA->getTag() == 5) // A가 아이템 B가 플레이어
			{
				Item *item = (Item*)spriteA;
				if (item->itemNum == 1)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					int temp = player->activeItem;

					player->activeItem = 1;
					item->itemNum = temp;
					item->removeAllChildren();
					item->addItem();
				}
				else if (item->itemNum == 2)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					int temp = player->activeItem;

					player->activeItem = 2;
					item->itemNum = temp;
					item->removeAllChildren();
					item->addItem();
				}
				else if (item->itemNum == 3)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					int temp = player->activeItem;

					player->activeItem = 3;
					item->itemNum = temp;
					item->removeAllChildren();
					item->addItem();
				}
				else if (item->itemNum == 4)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					int temp = player->activeItem;

					player->activeItem = 4;
					item->itemNum = temp;
					item->removeAllChildren();
					item->addItem();
				}
				else if (item->itemNum == 5)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 2;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += -0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += 0.5;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += 5;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 2;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->missileNum = 5;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 6)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 2;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += 0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += -1.5;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += 2;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 1;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->nowEnergy += -2;
					player->energy->setTexture2(player->nowEnergy);

					player->itemImage[6] = 1;


					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 7)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 1;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;


					player->speed += -0.5;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += 5;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;



					player->nowEnergy += 3;
					player->energy->setTexture2(player->nowEnergy);

					player->itemImage[7] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 8)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 4;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += 0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += -1;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += -5;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 5;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->nowEnergy += 1;
					player->energy->setTexture2(player->nowEnergy);

					player->itemImage[8] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 9)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 5;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += -0.2;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += 1;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += 10;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 1;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->missileNum = 4;
					player->itemImage[9] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 10)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);

					player->attackSpeed += -0.2;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += 1;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += -5;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->itemImage[10] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 11)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += -1;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += -0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->speed += 1;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;

					player->missileSpeed += -3;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->itemImage[11] = 1;



					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 12)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 3;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;

					player->attackSpeed += 0.1;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;


					player->missileSpeed += 3;
					if (player->missileSpeed < 5)
						player->missileSpeed = 5;
					else if (player->missileSpeed > 20)
						player->missileSpeed = 20;

					player->nukBack += 5;
					if (player->nukBack < 0.5)
						player->nukBack = 0.5;
					else if (player->nukBack > 10)
						player->nukBack = 10;

					player->missileNum = 2;
					player->itemImage[12] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 13)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->speed += 2;
					if (player->speed < 2.5)
						player->speed = 2.5;
					else if (player->speed > 4)
						player->speed = 4;


					player->itemImage[13] = 1;
					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 14)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);
					player->power += 2;
					if (player->power < 1)
						player->power = 1;
					else if (player->power > 5)
						player->power = 5;


					player->itemImage[14] = 1;
					item->itemNum = 0;
					item->removeAllChildren();
				}
				else if (item->itemNum == 15)
				{
					SimpleAudioEngine::getInstance()->playEffect(ITEM_GET);

					player->attackSpeed += -0.2;
					if (player->attackSpeed < 0.2)
						player->attackSpeed = 0.2;
					else if (player->attackSpeed > 0.7)
						player->attackSpeed = 0.7;

					player->missileNum = 3;
					player->itemImage[15] = 1;

					item->itemNum = 0;
					item->removeAllChildren();
				}
				
			}
		}
	}
	

	if (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_dynamicBody)
	{
		if (spriteA != nullptr && spriteB != nullptr)
		{
			if (spriteA->getTag() == 2 && spriteB->getTag() == 3) // 몬스터와 미사일충돌  A가 몬스터  B가 미사일 일때
			{
				Monster *monsterSprite = (Monster*)spriteA;
				monsterSprite->nowEnergy -= player->power;
				if (monsterSprite->nowEnergy <= 0 )
				{
					//monsterSprite->isAlive = false;
					monsterSprite->DeadAction();
					bodyA->SetUserData(nullptr);
				}
				else
					monsterSprite->HittedAction();

			}
			else if (spriteB->getTag() == 2 && spriteA->getTag() == 3) // 몬스터와 미사일충돌  B가 몬스터  A가 미사일 일때
			{
				Monster *monsterSprite = (Monster*)spriteB;
				monsterSprite->nowEnergy -= player->power;
				if (monsterSprite->nowEnergy <= 0)
				{
					monsterSprite->DeadAction();
					bodyB->SetUserData(nullptr);
				}
				else
					monsterSprite->HittedAction();

			}
			else if (spriteA->getTag() == 1 && spriteB->getTag() == 2) // 주인공과 몬스터 충돌  A가 주인공  B가 몬스터일 일때
			{
				Monster *monsterSprite = (Monster*)spriteB;
				monsterSprite->AttackAction();
				monsterSprite->AfterAttack();
				if (player->hitted == false)
				{
					SimpleAudioEngine::getInstance()->playEffect(PLAYER_HITTED);
					player->nowEnergy -= monsterSprite->power;
					player->hitted = true;
					
					if (player->nowEnergy <= 0)
					{
						player->nowEnergy = 0;
						player->alive = false;
						player->energy->setTexture2(player->nowEnergy);
						player->energy->hitMotion();
						player->DeadAction();   //Game Over
						//bodyA->SetUserData(nullptr);

						// 죽었을때 함수
					}
					else
					{
						player->hitting = false;
						player->energy->setTexture2(player->nowEnergy);
						player->energy->hitMotion();
						player->Delay();
						if (player->isFlippedX())
							bodyB->SetLinearVelocity(b2Vec2(50, 0));
						else
							bodyB->SetLinearVelocity(b2Vec2(-50, 0));
						player->HittedAction();
					}
				}

			}
			else if (spriteB->getTag() == 1 && spriteA->getTag() == 2) // 주인공과 몬스터 충돌 B가 주인공 A가 몬스터 일때
			{
				Monster *monsterSprite = (Monster*)spriteA;
				monsterSprite->AttackAction();
				monsterSprite->AfterAttack();
				if(player->hitted == false)
				{
					SimpleAudioEngine::getInstance()->playEffect(PLAYER_HITTED);
					player->nowEnergy -= monsterSprite->power;
					player->hitted = true;
					
					if (player->nowEnergy <= 0)
					{
						player->nowEnergy = 0;
						player->alive = false;
						player->energy->setTexture2(player->nowEnergy);
						player->energy->hitMotion();
						player->DeadAction();   //Game Over
						//bodyB->SetUserData(nullptr);
						// 죽었을때 함수
					}
					else
					{
						player->hitting = false;
						player->energy->setTexture2(player->nowEnergy);
						player->energy->hitMotion();
						player->Delay();
						if (player->isFlippedX())
							bodyB->SetLinearVelocity(b2Vec2(50, 0));
						else
							bodyB->SetLinearVelocity(b2Vec2(-50, 0));
						player->HittedAction();
					}
				}

			}
			else if (spriteA->getTag() == 1 && spriteB->getTag() == 4) // 주인공과 보스미사일 충돌 A가 주인공 B가 미사일
			{
				BossMissile *MissleSprite = (BossMissile*)spriteB;

				if (player->hitted == false)
				{
					SimpleAudioEngine::getInstance()->playEffect(PLAYER_HITTED);
					player->nowEnergy -= MissleSprite->power;
					player->hitted = true;

					if (player->nowEnergy <= 0)
					{
						player->nowEnergy = 0;
						player->alive = false;
						player->energy->setTexture2(player->nowEnergy);
						player->energy->hitMotion();
						player->DeadAction();   //Game Over
						//bodyA->SetUserData(nullptr);

						// 죽었을때 함수
					}
					else
					{
						player->hitting = false;
						player->energy->setTexture2(player->nowEnergy);
						player->energy->hitMotion();
						player->Delay();
						if (player->isFlippedX())
							bodyB->SetLinearVelocity(b2Vec2(50, 0));
						else
							bodyB->SetLinearVelocity(b2Vec2(-50, 0));
						player->HittedAction();
					}
				}

			}
			else if (spriteA->getTag() == 4 && spriteB->getTag() == 1) // 주인공과 보스미사일 충돌 B가 주인공 A가 미사일
			{
				BossMissile *MissleSprite = (BossMissile*)spriteA;

				if (player->hitted == false)
				{
					SimpleAudioEngine::getInstance()->playEffect(PLAYER_HITTED);
					player->nowEnergy -= MissleSprite->power;
					player->hitted = true;

					if (player->nowEnergy <= 0)
					{
						player->nowEnergy = 0;
						player->alive = false;
						player->energy->setTexture2(player->nowEnergy);
						player->energy->hitMotion();
						player->DeadAction();   //Game Over
						//bodyB->SetUserData(nullptr);

						// 죽었을때 함수
					}
					else
					{
						player->hitting = false;
						player->energy->setTexture2(player->nowEnergy);
						player->energy->hitMotion();
						player->Delay();
						if (player->isFlippedX())
							bodyB->SetLinearVelocity(b2Vec2(50, 0));
						else
							bodyB->SetLinearVelocity(b2Vec2(-50, 0));
						player->HittedAction();
					}
				}

			}
		}
	}

	//--------------미사일의 처리(부딫히면 사라진다)
	if (spriteA != nullptr)
	{
		if (spriteA->getTag() == 3)
		{
			SwordMissile *missileSprite = (SwordMissile*)spriteA;
			missileSprite->endAction(missileSprite->missileNum);
			bodyA->SetUserData(nullptr);
		}
	}
	if (spriteB != nullptr)
	{
		if (spriteB->getTag() == 3)
		{
			SwordMissile *missileSprite = (SwordMissile*)spriteB;
			missileSprite->endAction(missileSprite->missileNum);
			bodyB->SetUserData(nullptr);
		}
	}
	//---------------보스미사일 처리
	if (spriteA != nullptr)
	{
		if (spriteA->getTag() == 4)
		{
			BossMissile *missileSprite = (BossMissile*)spriteB;
			missileSprite->selfRemove();
			bodyA->SetUserData(nullptr);
		}
	}
	if (spriteB != nullptr)
	{
		if (spriteB->getTag() == 4)
		{
			BossMissile *missileSprite = (BossMissile*)spriteB;
			missileSprite->selfRemove();
			bodyB->SetUserData(nullptr);
		}
	}



/*
	if (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_dynamicBody)
	{

		auto spriteA = (Sprite*)bodyA->GetUserData();
		auto spriteB = (Sprite*)bodyB->GetUserData();

		if (spriteA != nullptr && spriteB != nullptr)
		{
			if (spriteA->getTag() == 3)
			{
				SwordMissile *missileSprite = (SwordMissile*)spriteA;
				missileSprite->endAction(missileSprite->missileNum);
				bodyA->SetUserData(nullptr);

			}
			else if (spriteB->getTag() == 3)
			{
				SwordMissile *missileSprite = (SwordMissile*)spriteB;
				missileSprite->endAction(missileSprite->missileNum);
				bodyB->SetUserData(nullptr);

			}


			if (spriteA->getTag() == 2 && spriteB->getTag() != 1)
			{
				Monster *monsterSprite = (Monster*)spriteA;
				monsterSprite->nowEnergy -= player->power;
				if (monsterSprite->nowEnergy <= 0)
				{
					monsterSprite->DeadAction();
					bodyA->SetUserData(nullptr);
				}
				else
					monsterSprite->HittedAction();


			}
			if (spriteA->getTag() == 1 && spriteB->getTag() == 2)
			{
				Monster *monsterSprite = (Monster*)spriteB;
				player->nowEnergy -= monsterSprite->power;
				if (player->nowEnergy <= 0)
				{
					player->DeadAction();
					bodyA->SetUserData(nullptr);
				}
				else
				{

				}
					


			}
		}



	}
*/



}

void ContactListener::EndContact(b2Contact *contact)
{


	//_world->DestroyBody(bodyA);
}

void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
	//CCLog("Contact:PreSolve");
}

void ContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
	

	//b2Fixture *fixA = contact->GetFixtureA();
	//b2Fixture *fixB = contact->GetFixtureB();

	//b2Body *bodyA = fixA->GetBody();
	//b2Body *bodyB = fixB->GetBody();
	//

	//if (bodyA->GetType() == b2_dynamicBody || bodyB->GetType() == b2_dynamicBody) {
	//	log("Contact:impulse .. %f", impulse->normalImpulses[0]);
	//}
}
