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
	Sprite *sprite;
	Sequence *seq;
	RepeatForever *seqR;
	switch (itemNum)
	{
	case 1:
		sprite = Sprite::create("item/active/lighter.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height+10 ));
		this->addChild(sprite);	
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 2:
		sprite = Sprite::create("item/active/redstar.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 3:
		sprite = Sprite::create("item/active/saw.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 4:
		sprite = Sprite::create("item/active/spiderweb.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 5:
		sprite = Sprite::create("item/passive/lazergun.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 6:
		sprite = Sprite::create("item/passive/cigarette.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 7:
		sprite = Sprite::create("item/passive/cross.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 8:
		sprite = Sprite::create("item/passive/dumbel.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 9:
		sprite = Sprite::create("item/passive/gamdekong.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 10:
		sprite = Sprite::create("item/passive/garlic.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 11:
		sprite = Sprite::create("item/passive/pensil.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 12:
		sprite = Sprite::create("item/passive/pipe.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 13:
		sprite = Sprite::create("item/passive/syringe_blue.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 14:
		sprite = Sprite::create("item/passive/syringe_red.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	case 15:
		sprite = Sprite::create("item/passive/syringe_yellow.png");
		sprite->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height + 10));
		this->addChild(sprite);
		seq = Sequence::create(MoveBy::create(1, Vec2(0, 10)), MoveBy::create(1, Vec2(0, -10)), nullptr);
		seqR = RepeatForever::create(seq);
		sprite->runAction(seqR);
		break;
	



	}
}

