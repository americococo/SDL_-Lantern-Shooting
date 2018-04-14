#include "Enemy.h"

#include "GameObject.h"

#include "Bullet.h"
#include "RotationBullet.h"
#include "ChaseBullet.h"
#include "aimingBullet.h"

#include "GameScene.h"

#include "SceneManger.h"
#include "BulletManger.h"
#include "GameObjectManger.h"

#include <map>
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

	_AttackCoolTime = 1000 / 10 * 3;
	_DuractionTime = 0;
	_hp = 100;

	angleright = true;

	_objectType = eObjectType::Monster;
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

	_DuractionTime += deltaTime;



	if (_AttackCoolTime <= _DuractionTime)
	{
		_DuractionTime = 0;
		this->Attack();
	}
}

void Enemy::Attack()
{
	//if (true == angleright)
	//{
	//	for (int i = 0; i <= 360; i += 30)
	//	{

	//		RotationBullet * bullet = new RotationBullet();

	//		int EnterBulletX = _x;
	//		int EnterBulletY = _y;
	//		bullet->Init("Bullet.csv");

	//		bullet->SetAngle(i);
	//		bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);

	//		((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
	//	}
	//}
	//if (false == angleright)
	//{
	//	for (int i = 15; i <= 375; i += 30)
	//	{
	//		RotationBullet * bullet = new RotationBullet();

	//		int EnterBulletX = _x;
	//		int EnterBulletY = _y;
	//		bullet->Init("Bullet.csv");

	//		bullet->SetAngle(i);
	//		bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);

	//		((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
	//	}
	//}
	//angleright = !angleright;

	std::map<int, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();

	for (itr; itr != ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetEnd(); itr++)
	{
		switch (itr->second->GetObjectType())
		{
		case eObjectType::Player:

			aimingBullet * bullet = new aimingBullet();
			int EnterBulletX = _x;
			int EnterBulletY = _y;
			bullet->Init("Bullet.csv");
			bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
			bullet->SetOwner(this);
			bullet->SetTargetPosition(itr->second->GetPostionX(), itr->second->GetPostionY());
			bullet->SetSpeed(5);
			((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
			break;
		}
	}



	//std::map<int, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();

	//for (itr; itr != ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetEnd(); itr++)
	//{
	//	switch (itr->second->GetObjectType())
	//	{
	//	case eObjectType::Player:
	//		ChaseBullet * bullet = new ChaseBullet();

	//		int EnterBulletX = _x;
	//		int EnterBulletY = _maxY + 50;
	//		bullet->Init("ChaseBullet.csv");
	//		bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
	//		bullet->SetTarget(itr->second);
	//		bullet->SetSpeed(5);
	//		
	//		((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
	//		break;
	//	}
	//}



}	