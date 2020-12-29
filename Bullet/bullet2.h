#pragma once
#include <cocos2d.h>
USING_NS_CC;

class bullet2 :public Node
{
public:
	bool init();
	CREATE_FUNC(bullet2);
	void update(float dt);

	float delay;

	Rect getBox();
};

