#pragma once
#include <cocos2d.h>
USING_NS_CC;
class Player :public Node
{
public:
	bool init();
	CREATE_FUNC(Player);

	int hp;

	//플레이어 객체의 움직임 관리
	void Press(EventKeyboard::KeyCode key, Event* e);
	void Release(EventKeyboard::KeyCode key, Event* e);
	void update(float dt);
	bool up, down, right, left;

	//플레이어 객체의 hitBox
	Rect getBox();

	static Player* getIns();
};