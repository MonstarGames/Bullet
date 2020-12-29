#include "bullet2.h"
#include "Player.h"

bool bullet2::init()
{
    Sprite* b = Sprite::create("shot_2.png");
    this->addChild(b);
    b->setName("bullet");

    delay = 0;

    return true;
}

void bullet2::update(float dt)
{
	delay += dt;
	if (delay >= 0.2f) {
		delay -= 0.2f;
       
        Sprite* b = (Sprite*)this->getChildByName("bullet");
		b->setPositionX(b->getPositionX() - 600 * dt);

		if (b->getPositionX() < -100) {
			this->removeFromParentAndCleanup(true);
			return;
		}
	}
    
    Player* p = Player::getIns();

    Rect rt1 = p->getBox();
    Rect rt2 = this->getBox();

    if (rt1.intersectsRect(rt2) == true) {
        p->removeFromParentAndCleanup(true);
        this->removeFromParentAndCleanup(true);
        return;
    }
}

Rect bullet2::getBox()
{
    Sprite* b = (Sprite*)this->getChildByName("bullet");
    Rect rt = b->getBoundingBox();
    rt.origin += this->getPosition();

    return rt;
}
