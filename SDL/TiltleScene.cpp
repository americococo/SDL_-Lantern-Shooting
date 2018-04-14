#include "TiltleScene.h"
#include "SceneManger.h"
#include "gameSystem.h"

#include "Sprite.h"

#include "InputManager.h"
#include <SDL.h>
TitleScene::TitleScene()
{
	_backGround = new Sprite("background.csv", true);
}

TitleScene::~TitleScene()
{
}
void TitleScene::Init()
{
	_backGround->SetPostion(GameSystem::Getinstance()->GetWindowW() / 2, GameSystem::Getinstance()->GetWindowH() / 2);
}
void TitleScene::DeInit()
{
	if (_backGround != nullptr)
	{
		delete _backGround;
		_backGround = nullptr;
	}
}
void TitleScene::Render() 
{
	_backGround->Render();
}
void TitleScene::Update(int deltaTime)
{
	_backGround->Update(deltaTime);

	if (InputManager::GetInstance()->IsInputKey(SDLK_SPACE))
	{
		SceneManger::Getinstance()->ChangeScene(eSceneType::GAME);
	}
}