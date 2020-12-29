#include "bullet1.h"
#include "Player.h"

bool bullet1::init()
{
    Sprite* b = Sprite::create("shot_1.png");
    this->addChild(b);
    b->setName("bullet");

    delay = 0;

    return true;
}

void bullet1::update(float dt)
{
    delay += dt;
    Player* p = Player::getIns();

    if (delay >= 0.5f) {
        delay -= 0.5f;

        Sprite* b = (Sprite*)this->getChildByName("bullet");

        Vec2 final = p->getPosition();
        Vec2 start = this->getPosition();
        dir = final - start;
        dir = dir.getNormalized();

        b->setPosition(b->getPosition() + dir * 300 * dt);

        if (b->getPositionX() < -100) {
            this->removeFromParentAndCleanup(true);
            return;
        }
    }

    Rect rt1 = p->getBox();
    Rect rt2 = this->getBox();

    if (rt1.intersectsRect(rt2) == true) {
        p->removeFromParentAndCleanup(true);
        this->removeFromParentAndCleanup(true);
        return;
    }
}

Rect bullet1::getBox()
{
    Sprite* b = (Sprite*)this->getChildByName("bullet");
    Rect rt = b->getBoundingBox();
    rt.origin += this->getPosition();
    
    return rt;
}
