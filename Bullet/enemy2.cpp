#include "enemy2.h"

bool enemy2::init()
{
    /*포지션1 1000, 600
    포지션2 1000, 440
    포지션3 1000, 280
    포지션4 1000, 120*/

    Sprite* en2 = Sprite::create("enemy2.png");
    this->addChild(en2);
    en2->setName("en2");
    this->setPosition(Vec2(9999, 999));

    return true;
}

void enemy2::enemy2_Active(int y)
//에너미 활성화 함수
{
    this->setPosition(Vec2(1325, 600 - 160 * y));
    /*y가 0 = 600
    y가 1 = 440
    y가 2 = 280
    y가 3 = 120*/

    this->addChild(b);
    b->makeBullet2(this->getPosition());

    MoveBy* mby1 = MoveBy::create(1, Vec2(-325, 0));
    DelayTime* dt = DelayTime::create(10);
    MoveBy* mby2 = MoveBy::create(2, Vec2(0, 800));

    Sequence* seq = Sequence::create(mby1, dt, mby2, 0);

    this->setVisible(true);
    this->runAction(seq);
}

void enemy2::enemy2_DisAct()
//에너미 비활성화 함수
{
    this->stopAllActions();
    this->setVisible(false);
}

Rect enemy2::getBox()
//충돌 박스 보정 함수
{
    Sprite* en2 = (Sprite*)this->getChildByName("en2");
    Rect rt = en2->getBoundingBox();
    rt.origin += this->getPosition();

    return rt;
}