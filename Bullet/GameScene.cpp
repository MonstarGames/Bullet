#include "GameScene.h"
#include "Player.h"
#include "enemyManager.h"
#include "laserManager.h"

bool GameScene::init()
{
    Player* p = Player::getIns();
    this->addChild(p);

    enemyManager* e = enemyManager::getIns();
    this->addChild(e);

    laserManager* l = laserManager::getIns();
    this->addChild(l);

    return true;
}
