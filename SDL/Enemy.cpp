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


	{
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
