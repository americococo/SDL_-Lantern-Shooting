#include "Enemy.h"

#include "GameObject.h"

#include "RotationBulletPattern.h"
#include "ChaseBulletPattern.h"
#include "AimmingBulletPattern.h"

#include "Bullet.h"
#include "RotationBullet.h"
#include "ChaseBullet.h"
#include "aimingBullet.h"

#include "GameScene.h"

#include "SceneManger.h"
#include "BulletManger.h"
#include "GameObjectManger.h"

#include "MonsterIdleState.h"
#include "IdleState.h"
#include "MoveState.h"
#include "State.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}
void Enemy::Init(const char * name)
{
	GameObject::Init(name);
	_ObjectId = 10;

	_hp = 100;



	_objectType = eObjectType::Monster;

	{
		{
			State * state = new MonsterIdleState();
			state->Init(this);
			_stateMap[eStateType::IDLE] = state;
		}
		{
			State * state = new MoveState();
			state->Init(this);
			_stateMap[eStateType::MOVE] = state;
		}

	}


	{
		BulletPattern * pattern = new RotationBulletPattern();
		pattern->Init(this);
		_bulletPatternList[eBulletPattern::ROTATION] = pattern;
	}
	{
		BulletPattern * pattern = new ChaseBulletPattern();
		pattern->Init(this);
		_bulletPatternList[eBulletPattern::CHASE] = pattern;
	}
	{
		BulletPattern * pattern = new AimmingBulletPattern();
		pattern->Init(this);
		_bulletPatternList[eBulletPattern::AIMMING] = pattern;
	}

	changeState(eStateType::IDLE);

	_pattern = _bulletPatternList[eBulletPattern::ROTATION];
}
void Enemy::DeInit()
{
	GameObject::DeInit();
}
void Enemy::Render()
{
	if (false == _isLive)
		return;

	GameObject::Render();
}
void Enemy::Update(int deltaTime)
{
	if (false == _isLive)
		return;
	GameObject::Update(deltaTime);

	_state->Update(deltaTime);

	{
		_enemy = nullptr;
		std::map<int, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();
		for (itr; itr != ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetEnd(); itr++)
		{
			switch (itr->second->GetObjectType())
			{
			case eObjectType::Player:
				_enemy = itr->second;
				break;
			}
		}

		_pattern->Update(deltaTime);
		ChangePattern( (eBulletPattern)(rand() % 3));
		this->Attack();
	}
}

void Enemy::Attack()
{

}	
