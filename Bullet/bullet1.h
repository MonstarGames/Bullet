#pragma once
#include <cocos2d.h>
USING_NS_CC;

class bullet1 :public Node
{
public:
	bool init();
	CREATE_FUNC(bullet1);
	void update(float dt);

	Vec2 dir;
	float delay;

	Rect getBox();
};
