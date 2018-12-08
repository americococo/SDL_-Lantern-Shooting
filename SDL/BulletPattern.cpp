#include "BulletPattern.h"
#include "Bullet.h"
#include "GameScene.h"
#include "SceneManger.h"
#include "BulletManger.h"
#include "GameObjectManger.h"
#include "GameObject.h"

#include "Enemy.h"

BulletPattern::BulletPattern(int AttackCoolTime)
{
	_DuractionTime = 0;
	

	_AttackCoolTime = AttackCoolTime;

}

BulletPattern::~BulletPattern()
{
}
void BulletPattern::Init(GameObject * object)
{
	_object = object;
	
}
void BulletPattern::Update(int deltaTime)
{
	_DuractionTime += deltaTime;

	if (_DuractionTime >= _AttackCoolTime)
	{
		_DuractionTime = 0;
		Bullet * bullet = new Bullet();

		bullet->Init("Bullet.csv");
		int EnterBulletX = _object->GetPostionX();
		int EnterBulletY = _object->GetPostionY();

		bullet->SetOwner(_object);
		bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
		bullet->SetSpeed(-20);
		((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
	}

}