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

void Player::AttackAction(bool isMoving)
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
	Sequence *seq3;
	if(isMoving)
		seq3 = Sequence::create(animate3, CallFunc::create(CC_CALLBACK_0(Player::IdleAction, this)), nullptr);
	else
		seq3 = Sequence::create(animate3, CallFunc::create(CC_CALLBACK_0(Player::MoveAction, this)), nullptr);
		
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
	attackSpeed = 0.7;
	nowMagic = 10;
	nowEnergy = 20;
	power = 1;
	nukBack = 10;
	speed = 2.5;
	missileSpeed = 5;
	activeItem = 0;
	missileNum = 1;
	energy = new Energy();
	magicEnergy = new magic();

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

	getcigar = Sprite::create("item/face/getcigar.png");
	getcross = Sprite::create("item/face/getcross.png");
	getdumbel = Sprite::create("item/face/getdumbel.png");
	getgamdekong = Sprite::create("item/face/getgamdekong.png");
	getgarlic = Sprite::create("item/face/getgarlic.png");
	getpensil = Sprite::create("item/face/getpensil.png");
	getpipe = Sprite::create("item/face/getpipe.png");
	getblue = Sprite::create("item/face/getblue.png");
	getred = Sprite::create("item/face/getred.png");
	getyellow = Sprite::create("item/face/getyellow.png");
	
	getcigar->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height / 2));
	getcross->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	getdumbel->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	getgamdekong->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	getgarlic->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	getpensil->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	getpipe->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	getblue->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	getred->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
	getyellow->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));

	getcigar->setVisible(false);
	getcross->setVisible(false);
	getdumbel->setVisible(false);
	getgamdekong->setVisible(false);
	getgarlic->setVisible(false);
	getpensil->setVisible(false);
	getpipe->setVisible(false);
	getblue->setVisible(false);
	getred->setVisible(false);
	getyellow->setVisible(false);

	this->addChild(getcigar, 3);
	this->addChild(getcross, 2);
	this->addChild(getdumbel, 2);
	this->addChild(getgamdekong, 2);
	this->addChild(getgarlic, 1);
	this->addChild(getpensil, 3);
	this->addChild(getpipe, 3);
	this->addChild(getblue, 4);
	this->addChild(getred, 4);
	this->addChild(getyellow, 4);

	this->schedule(schedule_selector(Player::ItemImaging));
}
void Player::ChildFlip(bool flip)
{
	if (flip)
	{
		getcigar->setFlippedX(true);
		getcross->setFlippedX(true);
		getdumbel->setFlippedX(true);
		getgamdekong->setFlippedX(true);
		getgarlic->setFlippedX(true);
		getpensil->setFlippedX(true);
		getpipe->setFlippedX(true);
		getblue->setFlippedX(true);
		getred->setFlippedX(true);
		getyellow->setFlippedX(true);
	}
	else
	{
		getcigar->setFlippedX(false);
		getcross->setFlippedX(false);
		getdumbel->setFlippedX(false);
		getgamdekong->setFlippedX(false);
		getgarlic->setFlippedX(false);
		getpensil->setFlippedX(false);
		getpipe->setFlippedX(false);
		getblue->setFlippedX(false);
		getred->setFlippedX(false);
		getyellow->setFlippedX(false);
	}

}

void Player::ItemImaging(float dt)
{
	
	if (itemImage[6] == 1)   
	{
		if (!getcigar->isVisible())
			getcigar->setVisible(true);

	}
	if (itemImage[7] == 1)
	{
		if (!getcross->isVisible())
			getcross->setVisible(true);

	}
	if (itemImage[8] == 1)
	{
		if (!getdumbel->isVisible())
			getdumbel->setVisible(true);

	}
	if (itemImage[9] == 1)
	{
		if (!getgamdekong->isVisible())
			getgamdekong->setVisible(true);

	}
	if (itemImage[10] == 1)
	{
		if (!getgarlic->isVisible())
			getgarlic->setVisible(true);

	}
	if (itemImage[11] == 1)
	{
		if (!getpensil->isVisible())
			getpensil->setVisible(true);

	}
	if (itemImage[12] == 1)
	{
		if (!getpipe->isVisible())
			getpipe->setVisible(true);

	}
	if (itemImage[13] == 1)
	{
		if (!getblue->isVisible())
			getblue->setVisible(true);

	}
	if (itemImage[14] == 1)
	{
		if (!getred->isVisible())
			getred->setVisible(true);

	}
	if (itemImage[15] == 1)
	{
		if (!getyellow->isVisible())
			getyellow->setVisible(true);

	}

}