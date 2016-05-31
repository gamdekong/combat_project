#include "Energy.h"



Energy::Energy()
{
	
	energy0 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy0.png");
	energy1 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy1.png");
	energy2 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy2.png");
	energy3 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy3.png");
	energy4 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy4.png");
	energy5 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy5.png");
	energy6 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy6.png");
	energy7 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy7.png");
	energy8 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy8.png");
	energy9 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy9.png");
	energy10 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy10.png");
	energy11 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy11.png");
	energy12 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy12.png");
	energy13 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy13.png");
	energy14 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy14.png");
	energy15 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy15.png");
	energy16 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy16.png");
	energy17 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy17.png");
	energy18 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy18.png");
	energy19 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy19.png");
	energy20 = Director::getInstance()->getTextureCache()->addImage("ui/energy/energy20.png");

	init2();

}

void Energy::setTexture2(int energy)
{
	switch (energy)
	{
	case 0:
		this->setTexture(energy0);
		break;
	case 1:
		this->setTexture(energy1);
		break;
	case 2:
		this->setTexture(energy2);
		break;
	case 3:
		this->setTexture(energy3);
		break;
	case 4:
		this->setTexture(energy4);
		break;
	case 5:
		this->setTexture(energy5);
		break;
	case 6:
		this->setTexture(energy6);
		break;
	case 7:
		this->setTexture(energy7);
		break;
	case 8:
		this->setTexture(energy8);
		break;
	case 9:
		this->setTexture(energy9);
		break;
	case 10:
		this->setTexture(energy10);
		break;
	case 11:
		this->setTexture(energy11);
		break;
	case 12:
		this->setTexture(energy12);
		break;
	case 13:
		this->setTexture(energy13);
		break;
	case 14:
		this->setTexture(energy14);
		break;
	case 15:
		this->setTexture(energy15);
		break;
	case 16:
		this->setTexture(energy16);
		break;
	case 17:
		this->setTexture(energy17);
		break;
	case 18:
		this->setTexture(energy18);
		break;
	case 19:
		this->setTexture(energy19);
		break;
	case 20:
		this->setTexture(energy20);
		break;

	

	}
}

void Energy::init2()
{
	this->initWithTexture(energy20);
	this->setPosition(Vec2(120 , 50));
	this->setAnchorPoint(Vec2(0, 0.5));
}

void Energy::hitMotion()
{
	auto seq = Sequence::create(FadeOut::create(0.1), FadeIn::create(0.1), nullptr);
	this->runAction(seq);
}
