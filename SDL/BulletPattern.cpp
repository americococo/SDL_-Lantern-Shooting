#include "BulletPattern.h"
#include "Bullet.h"
#include "GameScene.h"
#include "SceneManger.h"
#include "BulletManger.h"
#include "GameObjectManger.h"
#include "GameObject.h"

#include "Enemy.h"

BulletPattern::BulletPattern()
{
	_DuractionTime = 0;
	_AttackCoolTime = 1000 * 0.5;
	_ChangeCoolTime = 1000 * 1.0;
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

		int EnterBulletX = _object->GetPostionX();
		int EnterBulletY = _object->GetPostionMinY();
		bullet->Init("Bullet.csv");
		bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
		bullet->SetSpeed(-20);
		((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
	}
}