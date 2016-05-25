#include "Player.h"



void Player::IdleAction()
{
	this->stopAllActions();
	//--------ÈÞ½Ä
	auto animation2 = Animation::create();
	animation2->setDelayPerUnit(0.2);
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;

		animation2->addSpriteFrameWithTexture(playerIdleTexture, Rect(160 * column, 0, 160, 120));
	}

	auto animate2 = Animate::create(animation2);

	auto seq2 = Sequence::create(animate2, nullptr);
	auto playerIdleSeq = RepeatForever::create(seq2);
	this->runAction(playerIdleSeq);
}

void Player::AttackAction()
{
	this->stopAllActions();
	auto animation3 = Animation::create();
	animation3->setDelayPerUnit(0.1);
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;

		animation3->addSpriteFrameWithTexture(playerAttackTexture, Rect(160 * column, 0, 160, 120));
	}

	auto animate3 = Animate::create(animation3);

	auto seq3 = Sequence::create(animate3, CallFunc::create(CC_CALLBACK_0(Player::IdleAction,this)),nullptr);
	//auto playerAttackSeq = RepeatForever::create(seq3);
	this->runAction(seq3);
}

void Player::DeadAction()
{
	this->stopAllActions();
	auto animation4 = Animation::create();
	animation4->setDelayPerUnit(0.1);
	for (int i = 0; i < 6; i++)
	{
		int column = i % 6;

		animation4->addSpriteFrameWithTexture(playerDeadTexture, Rect(160 * column, 0, 160, 120));
	}

	auto animate4 = Animate::create(animation4);

	auto seq4 = Sequence::create(animate4, nullptr);
	//auto playerDeadSeq = RepeatForever::create(seq4);
	this->runAction(seq4);
}

void Player::MoveAction()
{
	this->stopAllActions();
	auto animation1 = Animation::create();
	animation1->setDelayPerUnit(0.1);
	for (int i = 0; i < 6; i++)
	{
		int column = i % 6;

		animation1->addSpriteFrameWithTexture(playerMoveTexture, Rect(160 * column, 0, 160, 120));
	}

	auto animate1 = Animate::create(animation1);

	auto seq1 = Sequence::create(animate1, nullptr);
	auto playerMoveSeq = RepeatForever::create(seq1);

	this->runAction(playerMoveSeq);
}

void Player::HittedAction()
{
	this->schedule(schedule_selector(Player::hittedAction2));
	
	

}
void Player::hittedAction2(float dt)
{
	if (hitCount == 0)
	{
		count = count - 30;
		if (count < 0)
			count = 0;
		this->setOpacity(count);
		if (count == 0)
			hitCount = 1;
	}
	else if (hitCount == 1)
	{
		count = count + 30;
		if (count > 255)
			count = 255;
		this->setOpacity(count);
		if (count == 255)
			hitCount = 2;

	}
	else if (hitCount == 2)
	{
		count = count - 30;
		if (count < 0)
			count = 0;
		this->setOpacity(count);
		if (count == 0)
			hitCount = 3;

	}
	else if (hitCount == 3)
	{
		count = count + 30;
		if (count > 255)
			count = 255;
		this->setOpacity(count);
		if (count == 255)
		{
			this->unschedule(schedule_selector(Player::hittedAction2));
			hitCount = 0;
		}

	}
		


}

void Player::ChangeHitted(float df)
{
	
	hitted = false;
}
void Player::ChangeHitting(float df)
{
	hitting = true;
}
void Player::Delay()
{
	this->scheduleOnce(schedule_selector(Player::ChangeHitted), 1);
	this->scheduleOnce(schedule_selector(Player::ChangeHitting), 0.2);

}

Player::Player()
{
	attackSpeed = 0.2;
	nowEnergy = 50;
	power = 1;
	nukBack = 0.5;
	energy = new Energy();

	playerMoveTexture = Director::getInstance()->getTextureCache()->addImage("player/move/move.png");
	playerAttackTexture = Director::getInstance()->getTextureCache()->addImage("player/attack/attack.png");
	playerIdleTexture = Director::getInstance()->getTextureCache()->addImage("player/idle/idle.png");
	playerDeadTexture = Director::getInstance()->getTextureCache()->addImage("player/dead/dead.png");

	this->init2();

}

void Player::init2()
{
	this->initWithTexture(playerIdleTexture, Rect(0, 0, 160, 120));
	this->setPosition(Vec2(300, 200));
	this->setTag(1);
}
