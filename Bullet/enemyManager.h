#pragma once
#include <cocos2d.h>
USING_NS_CC;

#include "enemy1.h"
#include "enemy2.h"

class enemyManager :public Layer
{
public:
	bool init();

	Vector<enemy1*> e1_vec;
	//현재 화면에서 사용중인 객체를 저장하는 벡터
	Vector<enemy1*> e1_vec_wait;
	//아직 사용하기 전인 객체를 저장하는 벡터

	Vector<enemy2*> e2_vec;
	Vector<enemy2*> e2_vec_wait;

	void update(float dt);

	float e1_timer, e2_timer;
	//에너미1,2 생성 타이머

	int e2_y;
	//에너미2 y축 정하는 int

	static enemyManager* getIns();

private:
	CREATE_FUNC(enemyManager);
};

