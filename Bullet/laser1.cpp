#include "laser1.h"
#include "enemyManager.h"
#include "enemy1.h"

bool laser1::init()
{
    Sprite* laser = Sprite::create("BULLET.png");
    this->addChild(laser);
    laser->setName("laser");

    this->scheduleUpdate();

    return true;
}

void laser1::update(float dt)
{
    Sprite* l = (Sprite*)this->getChildByName("laser");
    l->setPositionX(l->getPositionX() + 400 * dt);

    if (l->getPositionX() > 1300) {
        this->removeFromParentAndCleanup(true);
        return;
    }

    enemyManager* em = enemyManager::getIns();

    if (em->e1_vec.empty() != true) {
        for (Node* p : em->e1_vec) {
            enemy1* e = (enemy1*)p;
            Rect rt1 = e->getBox();
            Rect rt2 = this->getBox();

            if (rt1.intersectsRect(rt2) == true) {
                em->e1_vec_wait.pushBack(e);
                em->e1_vec.eraseObject(e);
                e->enemy1_DisAct();
                this->removeFromParentAndCleanup(true);
                return;
            }
        }
    }

    if (em->e2_vec.empty() != true) {
        for (Node* p : em->e2_vec) {
            enemy2* e = (enemy2*)p;
            Rect rt1 = e->getBox();
            Rect rt2 = this->getBox();

            if (rt1.intersectsRect(rt2) == true) {
                em->e2_vec_wait.pushBack(e);
                em->e2_vec.eraseObject(e);
                e->enemy2_DisAct();
                this->removeFromParentAndCleanup(true);
                return;
            }
        }
    }
}

Rect laser1::getBox()
{
    Sprite* l = (Sprite*)this->getChildByName("laser");
    Rect rt = l->getBoundingBox();
    rt.origin += this->getPosition();

    return rt;
}

