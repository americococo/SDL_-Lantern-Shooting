#include "PlayerobcaleCal.h"
#include "Sprite.h"

#include "GameObject.h"
#include "GameObjectManger.h"

#include"Bullet.h"
#include "BulletManger.h"

#include "GameScene.h"
#include "SceneManger.h"

#include "BulletPattern.h"
#include "ChaseBulletPattern.h"


#include "InputManager.h"
#include "State.h"
#include "IdleState.h"
#include "MoveState.h"

#include "GameSystem.h"

#include <SDL.h>
#include <stdio.h>

PlayerObcaleCal::PlayerObcaleCal()
{

}

PlayerObcaleCal::~PlayerObcaleCal()
{

}
void PlayerObcaleCal::Init(const char * name)
{
	_state = nullptr;
	GameObject::Init(name);

	_speed = 15;
	{
		{
			IdleState * state = new IdleState();
			state->Init(this);
			_stateMap[eStateType::IDLE] = state;
		}
		{
			State * state = new MoveState();
			state->Init(this);
			_stateMap[eStateType::MOVE] = state;
		}
	}

	_dot = new Sprite("PlayerDotSprite.csv", true);
	
	changeState(eStateType::IDLE);
	
	_objectType = eObjectType::Player;
} 
void PlayerObcaleCal::SetUpdate(int num)
{
	ChangePattern(num);
}

void PlayerObcaleCal::changeState(eStateType type)
{
	if (_state != nullptr)
	{
		_state->Stop();
		_state = nullptr;
	}

	_state = _stateMap[type];
	_state->Start();
}
void PlayerObcaleCal::SetPostion(float x,float y)
{
	_sprite->SetPostion(x, y);
	_dot->SetPostion(x, y);
	_x = x;
	_y = y;

	_minX = x - _dot->GetSpriteRangeX() / 2;
	_maxX = x + _dot->GetSpriteRangeX() / 2;

	_minY = y - _dot->GetSpriteRangeY() / 2;
	_maxY = y + _dot->GetSpriteRangeY() / 2;

	if (_x >= (GameSystem::Getinstance()->GetGameScreenRight()))
		_x = GameSystem::Getinstance()->GetGameScreenRight();

	if (_y >= (GameSystem::Getinstance()->GetGameScreenBottom()))
		_y = GameSystem::Getinstance()->GetGameScreenBottom();

	if (_x <= GameSystem::Getinstance()->GetGameScreenLeft())
		_x = GameSystem::Getinstance()->GetGameScreenLeft();

	if (_y <= GameSystem::Getinstance()->GetGameScreenTop())
		_y = GameSystem::Getinstance()->GetGameScreenTop();
}

void PlayerObcaleCal::DeInit()
{
	GameObject::DeInit();

	if (_sprite != nullptr)
	{
		delete _sprite;
		_sprite = nullptr;
	}
}
void PlayerObcaleCal::Render()
{
	if (false == _isLive)
		return;

	GameObject::Render();

	_dot->Render();
}
void PlayerObcaleCal::Update(int deltaTime)
{
	if (false == _isLive)
		return;
	GameObject::Update(deltaTime);

	_dot->Update(deltaTime);

 	_state->Update(deltaTime);


	_enemy.clear();

	std::map<std::wstring, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();

	for (itr; itr != ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetEnd(); itr++)
	{
		if(itr->second->GetObjectType()== eObjectType::Monster)
		{
			_enemy.push_back(itr->second);
		}
	}
	
	//if (InputManager::GetInstance()->IsInputKey(SDLK_z))
	_pattern->Update(deltaTime);

	if (InputManager::GetInstance()->IsInputKey(SDLK_x))
	{
		SetUpdate(1);
	}
	if (false == InputManager::GetInstance()->IsInputKey(SDLK_x))
	{
		SetUpdate(2);
	}


	if (InputManager::GetInstance()->IsInputKey(SDLK_LSHIFT))
	{
		_speed = 5.3f;
	}
	if (false == InputManager::GetInstance()->IsInputKey(SDLK_LSHIFT))
	{
		_speed = 12;
	}

}
