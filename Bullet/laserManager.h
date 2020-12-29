#pragma once
#include <cocos2d.h>
USING_NS_CC;
#include "laser1.h"

class laserManager :public Layer
{
public:
	bool init();
	void update(float dt);

	float l1_delay;

	static laserManager* getIns();

private:
	CREATE_FUNC(laserManager);
};
