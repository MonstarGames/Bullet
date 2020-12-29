#include "laserManager.h"
#include "Player.h"

static laserManager* obj = 0;

bool laserManager::init()
{
    l1_delay = 0;

    this->scheduleUpdate();

    return true;
}

void laserManager::update(float dt)
{
    l1_delay += dt;
    if (l1_delay >= 0.3f) {
        l1_delay -= 0.3f;
        laser1* l = laser1::create();
        this->addChild(l);

        Player* p = Player::getIns();
        l->setPositionX(p->getPositionX() + 90);
        l->setPositionY(p->getPositionY());
    }
}

laserManager* laserManager::getIns()
{
    if (obj == 0)
    {
        obj = laserManager::create();
    }
    return obj;
}
