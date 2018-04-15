#include "Enemy.h"

#include "GameObject.h"

#include "RotationBulletPattern.h"
#include "ChaseBulletPattern.h"

#include "Bullet.h"
#include "RotationBullet.h"//삭제 예정
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
		_pattern->Update(deltaTime);
		this->Attack();
	}
}

void Enemy::Attack()
{

	//std::map<int, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();

	//for (itr; itr != ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetEnd(); itr++)
	//{
	//	switch (itr->second->GetObjectType())
	//	{
	//	case eObjectType::Player:

	//		aimingBullet * bullet = new aimingBullet();
	//		int EnterBulletX = _x;
	//		int EnterBulletY = _y;
	//		bullet->Init("Bullet.csv");
	//		bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
	//		bullet->SetOwner(this);
	//		bullet->SetTargetPosition(itr->second->GetPostionX(), itr->second->GetPostionY());
	//		bullet->SetSpeed(5);
	//		((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
	//		break;
	//	}
	//}



}	
void Enemy::ChangePattern(eBulletPattern patternType)
{
	_pattern = _bulletPatternList[patternType];
}