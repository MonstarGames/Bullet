#include "enemy1.h"
//#include "bulletManager.h"

bool enemy1::init()
{
    Sprite* en1 = Sprite::create("enemy1.png");
    this->addChild(en1);
    en1->setName("en1");
    this->setPosition(Vec2(9999, 999));

    enemy1_DisAct();

    return true;
}

void enemy1::enemy1_Active()
//에너미 활성화 함수
{
    int ranY = rand() % 671 + 25;
    this->setPosition(Vec2(1315, ranY));

    MoveBy* mby = MoveBy::create(2, Vec2(-1360, 0));

    /* bulletManager* b = bulletManager::getIns();
    this->addChild(b);
    b->makeBullet1(this->getPosition());*/

    this->setVisible(true);
    this->runAction(mby);
}

void enemy1::enemy1_DisAct()
//에너미 비활성화 함수
{
    this->stopAllActions();
    this->setVisible(false);
}

Rect enemy1::getBox()
//충돌 박스 보정 함수
{
    Sprite* en1 = (Sprite*)this->getChildByName("en1");
    Rect rt = en1->getBoundingBox();
    rt.origin += this->getPosition();

    return rt;
}