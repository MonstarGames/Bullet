#pragma once
#include <cocos2d.h>
USING_NS_CC;
#include "bullet2.h"

#include "enemy2.h"

class bulletManager :public Layer
{
public:
	bool init();
	void update(float dt);

	float b1_delay, b2_delay;

	static bulletManager* getIns();



	void makeBullet1(Vec2 pos);
	void makeBullet2(Vec2 pos);

private:
	CREATE_FUNC(bulletManager);
};

