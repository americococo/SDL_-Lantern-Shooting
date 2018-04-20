#include "ChaseBulletPattern.h"
#include "GameScene.h"
#include "SceneManger.h"
#include "BulletManger.h"
#include "GameObjectManger.h"
#include "GameObject.h"


#include "ChaseBullet.h"
#include "Enemy.h"
#include <stdio.h>
#include <map>
ChaseBulletPattern::ChaseBulletPattern(int AttackCoolTime):BulletPattern(AttackCoolTime)
{
	
}
ChaseBulletPattern::~ChaseBulletPattern() {}

void ChaseBulletPattern::Update(int deltaTime)
{
	_DuractionTime += deltaTime;

	if (_DuractionTime >= _AttackCoolTime)
	{
		_DuractionTime = 0;


		if(nullptr != _object->GetEnemy())
		{
			ChaseBullet * bullet = new ChaseBullet();

			bullet->Init("ChaseBullet.csv");
			int EnterBulletX = _object->GetPostionX();
			int EnterBulletY = _object->GetPostionY();

			bullet->SetOwner(_object);
			bullet->SetTarget(_object->GetEnemy());

			bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
			bullet->SetSpeed(5);

			((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);

		}


	}

}