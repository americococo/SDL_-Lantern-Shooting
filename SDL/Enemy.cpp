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



	changeState(eStateType::IDLE);

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
		_enemy.clear();
		std::map<std::wstring, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();
		for (itr; itr != ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetEnd(); itr++)
		{
			switch (itr->second->GetObjectType())
			{
			case eObjectType::Player:
				_enemy.push_back(itr->second);
				break;
			}
		}

		ChangePattern((rand()%_bulletPatternList.size() + 1));


		_pattern->Update(deltaTime);


		
		
	}
}
