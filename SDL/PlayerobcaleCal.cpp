#include "PlayerobcaleCal.h"
#include "Sprite.h"

#include "GameObject.h"
#include "GameObjectManger.h"

#include"Bullet.h"
#include "BulletManger.h"

#include "GameScene.h"
#include "SceneManger.h"

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
	

	_AttackCoolTime = 1000 / 10 * 5;
	_DuractionTime = 0;

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


	if (InputManager::GetInstance()->IsInputKey(SDLK_SPACE))
		this->Attack();


	_DuractionTime += deltaTime;

}

void PlayerObcaleCal::Attack()
{
	if (_AttackCoolTime <= _DuractionTime)
	{
		_DuractionTime = 0;

		Bullet * bullet = new Bullet();

		int EnterBulletX = _x;
		int EnterBulletY = _minY ;
		bullet->Init("Bullet.csv");
		bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
		bullet->SetSpeed(-20);
		((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);

	}
}
