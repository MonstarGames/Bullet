#pragma once
#include <cocos2d.h>
USING_NS_CC;

//길막하고 총알쏘는 에너미

class enemy2 :public Node
{
public:
	bool init();
	CREATE_FUNC(enemy2);

	void enemy2_Active(int y), enemy2_DisAct();
	Rect getBox();
};