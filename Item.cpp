#include "Item.h"



Item::Item(int num)
{
	itemNum = num;
	
	texture = Director::getInstance()->getTextureCache()->addImage("structure/holydesk.png");
	init2();

}
void Item::init2()
{
	this->initWithTexture(texture);
	this->addItem();
	this->setTag(5);

	
}
void Item::addItem()
{
	switch (itemNum)
	{
	case 1:
		auto sprite = Sprite::create("item/active/lighter.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height+10 ));
		this->addChild(sprite);	
		auto seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		auto seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	



	}
}

