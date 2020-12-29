#include "bulletManager.h"
#include "enemyManager.h"

#include "bullet1.h"
#include "bullet2.h"

static bulletManager* obj = 0;

bool bulletManager::init()
{
    return true;
}

void bulletManager::update(float dt)
{

}

bulletManager* bulletManager::getIns()
{
    if (obj == 0)
    {
        obj = bulletManager::create();
    }
    return obj;
}

void bulletManager::makeBullet1(Vec2 pos)
{
    bullet1* b1 = bullet1::create();
    this->addChild(b1);
    b1->setPosition(pos);
}

void bulletManager::makeBullet2(Vec2 pos)
{
    bullet2* b2 = bullet2::create();
    this->addChild(b2);
    b2->setPosition(pos);
}
