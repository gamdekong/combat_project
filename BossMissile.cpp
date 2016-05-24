#include "BossMissile.h"

BossMissile::BossMissile(int num)
{
	this->init2(num);
}

void BossMissile::init2(int num)
{
	missile = Director::getInstance()->getTextureCache()->addImage("missile/bossfire.png");
	switch (num)
	{
	case 1:
		this->initWithTexture(missile, Rect(0, 0, 71, 55));
		break;
		

	}
	this->missileNum = num;
	this->setTag(4);
}


void BossMissile::startAction()
{ 

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1);

	switch (missileNum)
	{
	case 1:
		animation->addSpriteFrameWithTexture(missile, Rect(0, 0, 71, 55));
		animation->addSpriteFrameWithTexture(missile, Rect(71, 0, 71, 55));
		animation->addSpriteFrameWithTexture(missile, Rect(142, 0, 71, 55));
		animation->addSpriteFrameWithTexture(missile, Rect(213, 0, 71, 55));
		break;

	}
	auto animate = Animate::create(animation);
	auto seq = Sequence::create(animate, nullptr);
	auto seqR = RepeatForever::create(seq);
	this->runAction(seqR);



}