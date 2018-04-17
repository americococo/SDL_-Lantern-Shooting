#include "GameScene.h"
#include "Sprite.h"
#include "gameSystem.h"
#include "PlayerobcaleCal.h"
#include "Enemy.h"	

#include "BulletManger.h"

#include "GameObjectManger.h"
#include "SceneManger.h"
#include "InputManager.h"
#include <SDL.h>
#include <stdio.h>
GameScene::GameScene()
{
	_backGround = new Sprite("GameBackGround.csv", true);
	
	_player = new PlayerObcaleCal();
	_enemy = new Enemy();

	_objectManger = new GameObjectManger();
	_bulletManger = new BulletManger();
}

GameScene::~GameScene()
{
}
void GameScene::Init()
{
	_backGround->SetPostion(GameSystem::Getinstance()->GetWindowCenterX(), GameSystem::Getinstance()->GetWindowCenterY());

	_player->Init("Player_Sprite.csv");
	_player->SetPostion(GameSystem::Getinstance()->GetWindowCenterX(), 750);

	_enemy->Init("Enemy_Sprite.csv");
	_enemy->SetPostion(GameSystem::Getinstance()->GetWindowCenterX(), 100);

	_objectManger->PushObjaceMap(_player);
	_objectManger->PushObjaceMap(_enemy);

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
