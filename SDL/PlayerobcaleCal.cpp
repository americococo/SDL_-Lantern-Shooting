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

	_hp = 10;

	_speed = 12;

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



	changeState(eStateType::IDLE);

	_objectType = eObjectType::Player;
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
void PlayerObcaleCal::DeInit()
{
	GameObject::DeInit();
}
void PlayerObcaleCal::Render()
{
	if (false == _isLive)
		return;

	GameObject::Render();
}
void PlayerObcaleCal::Update(int deltaTime)
{
	if (false == _isLive)
		return;
	GameObject::Update(deltaTime);


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
	



	if (InputManager::GetInstance()->IsInputKey(SDLK_z))
		_pattern->Update(deltaTime);

	if (InputManager::GetInstance()->IsInputKey(SDLK_x))
	{
		ChangePattern(2);
	}
	if (false == InputManager::GetInstance()->IsInputKey(SDLK_x))
	{
		ChangePattern(1);
	}


	if (InputManager::GetInstance()->IsInputKey(SDLK_LSHIFT))
	{
		_speed = 6;
	}
	if (false == InputManager::GetInstance()->IsInputKey(SDLK_LSHIFT))
	{
		_speed = 12;
	}


}
