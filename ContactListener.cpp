#include "ContactListener.h"
#include "SwordMissile.h"
#include "Monster.h"
#include "BossMissile.h"

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



	

	if (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_dynamicBody)
	{
		if (spriteA != nullptr && spriteB != nullptr)
		{
			if (spriteA->getTag() == 2 && spriteB->getTag() == 3) // ���Ϳ� �̻����浹  A�� ����  B�� �̻��� �϶�
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
			else if (spriteB->getTag() == 2 && spriteA->getTag() == 3) // ���Ϳ� �̻����浹  B�� ����  A�� �̻��� �϶�
			{
				Monster *monsterSprite = (Monster*)spriteB;
				monsterSprite->nowEnergy -= player->power;
				if (monsterSprite->nowEnergy <= 0)
				{
					monsterSprite->DeadAction();
					bodyA->SetUserData(nullptr);
				}
				else
					monsterSprite->HittedAction();

			}
			else if (spriteA->getTag() == 1 && spriteB->getTag() == 2) // ���ΰ��� ���� �浹  A�� ���ΰ�  B�� ������ �϶�
			{
				Monster *monsterSprite = (Monster*)spriteB;
				
				if (player->hitted == false)
				{
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

						// �׾����� �Լ�
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
			else if (spriteB->getTag() == 1 && spriteA->getTag() == 2) // ���ΰ��� ���� �浹 B�� ���ΰ� A�� ���� �϶�
			{
				Monster *monsterSprite = (Monster*)spriteA;
				
				if(player->hitted == false)
				{
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
						// �׾����� �Լ�
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
			else if (spriteA->getTag() == 1 && spriteB->getTag() == 4) // ���ΰ��� �����̻��� �浹 A�� ���ΰ� B�� �̻���
			{
				BossMissile *MissleSprite = (BossMissile*)spriteB;

				if (player->hitted == false)
				{
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

						// �׾����� �Լ�
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
			else if (spriteA->getTag() == 4 && spriteB->getTag() == 1) // ���ΰ��� �����̻��� �浹 B�� ���ΰ� A�� �̻���
			{
				BossMissile *MissleSprite = (BossMissile*)spriteA;

				if (player->hitted == false)
				{
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

						// �׾����� �Լ�
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

	//--------------�̻����� ó��(�΋H���� �������)
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
	//---------------�����̻��� ó��
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
