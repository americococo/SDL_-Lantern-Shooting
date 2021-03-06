#include "GameScene.h"
#include "Sprite.h"
#include "gameSystem.h"
#include "PlayerobcaleCal.h"
#include "Enemy.h"	

#include "BulletManger.h"

#include "RotationBulletPattern.h"
#include "AimmingBulletPattern.h"
#include "ChaseBulletPattern.h"
#include "BulletPattern.h"

#include "GameObjectManger.h"
#include "SceneManger.h"
#include "InputManager.h"
#include <SDL.h>
#include <stdio.h>
GameScene::GameScene()
{
	_backGround = new Sprite("GameBackGround.csv", true);
	
	_objectManger = new GameObjectManger();
	_bulletManger = new BulletManger();
}

GameScene::~GameScene()
{
}
void GameScene::Init()
{
	_backGround->SetPostion(GameSystem::Getinstance()->GetWindowCenterX(), GameSystem::Getinstance()->GetWindowCenterY());
	{
		GameObject * player = new PlayerObcaleCal();

		player->Init("PlayerInfo.csv");
		player->InitBulletParttern(new BulletPattern(1000*0.1), 1);
		player->InitBulletParttern(new ChaseBulletPattern(1000*0.5),2);

		player->SetPostion(GameSystem::Getinstance()->GetWindowCenterX(), 750);
		((PlayerObcaleCal*)player)->SetUpdate(1);
		_objectManger->PushObjaceMap(player, L"Player");
	}
	{
		GameObject * enemy = new Enemy();
		enemy->Init("EnemyInfo.csv");
		enemy->InitBulletParttern(new RotationBulletPattern(1000*0.2),1);
		enemy->InitBulletParttern(new AimmingBulletPattern(1000*0.5), 2);
		
		enemy->SetPostion(GameSystem::Getinstance()->GetWindowCenterX()-300, 100);
		_objectManger->PushObjaceMap(enemy, L"Enemy1");
	}
	{
		GameObject * enemy = new Enemy();
		enemy->Init("EnemyInfo.csv");
		enemy->InitBulletParttern(new ChaseBulletPattern(1000*0.8), 1);
		
		enemy->SetPostion(GameSystem::Getinstance()->GetWindowCenterX()+300, 100);
		_objectManger->PushObjaceMap(enemy, L"Enemy2");
	}
	{
		GameObject * enemy = new Enemy();
		enemy->Init("EnemyInfo.csv");
		enemy->InitBulletParttern(new ChaseBulletPattern(1000 * 0.8), 1);
		
		enemy->SetPostion(GameSystem::Getinstance()->GetWindowCenterX(),GameSystem::Getinstance()->GetWindowCenterY());
		_objectManger->PushObjaceMap(enemy, L"Enemy3");
	}

}
void GameScene::DeInit()
{
	if (_backGround != nullptr)
	{
		delete _backGround;
		_backGround = nullptr;
	}

	_objectManger->DeInit();
	_bulletManger->DeInit();
}
void GameScene::Render()
{
	_backGround->Render();
	_bulletManger->Render();
	_objectManger->Render();
}
void GameScene::Update(int deltaTime)
{
	_backGround->Update(deltaTime);
	_bulletManger->Update(deltaTime);

	_objectManger->Update(deltaTime);


	if (InputManager::GetInstance()->IsInputKey(SDLK_F1))
	{
		SceneManger::Getinstance()->ChangeScene(eSceneType::TITLE);
	}
}