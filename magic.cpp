#include "magic.h"



magic::magic()
{

	magic0 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic0.png");
	magic1 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic1.png");
	magic2 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic2.png");
	magic3 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic3.png");
	magic4 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic4.png");
	magic5 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic5.png");
	magic6 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic6.png");
	magic7 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic7.png");
	magic8 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic8.png");
	magic9 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic9.png");
	magic10 = Director::getInstance()->getTextureCache()->addImage("ui/magic/magic10.png");
	

	init2();

}

void magic::setTexture2(int magic)
{
	switch (magic)
	{
	case 0:
		this->setTexture(magic0);
		break;
	case 1:
		this->setTexture(magic1);
		break;
	case 2:
		this->setTexture(magic2);
		break;
	case 3:
		this->setTexture(magic3);
		break;
	case 4:
		this->setTexture(magic4);
		break;
	case 5:
		this->setTexture(magic5);
		break;
	case 6:
		this->setTexture(magic6);
		break;
	case 7:
		this->setTexture(magic7);
		break;
	case 8:
		this->setTexture(magic8);
		break;
	case 9:
		this->setTexture(magic9);
		break;
	case 10:
		this->setTexture(magic10);
		break;
	

	}
}

void magic::init2()
{
	this->initWithTexture(magic10);
	this->setPosition(Vec2(1070, 20));
	this->setAnchorPoint(Vec2(0, 0.5));
}

void magic::magicMotion()
{
	auto seq = Sequence::create(FadeOut::create(0.1), FadeIn::create(0.1), nullptr);
	this->runAction(seq);
}
