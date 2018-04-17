#include "ChaseBulletPattern.h"
#include "GameScene.h"
#include "SceneManger.h"
#include "BulletManger.h"
#include "GameObjectManger.h"
#include "GameObject.h"


#include "ChaseBullet.h"
#include "Enemy.h"
#include <map>
ChaseBulletPattern::ChaseBulletPattern()
{
	_AttackCoolTime = 1000 * 0.01;
}
ChaseBulletPattern::~ChaseBulletPattern() {}

void ChaseBulletPattern::Update(int deltaTime)
{
	_DuractionTime += deltaTime;

	if (_DuractionTime >= _AttackCoolTime)
	{
		_DuractionTime = 0;

		{

			ChaseBullet * bullet = new ChaseBullet();

			int EnterBulletX = _object->GetPostionX();
			int EnterBulletY = _object->GetPostionY();
			bullet->Init("ChaseBullet.csv");
			bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
			bullet->SetTarget(_object->GetEnemy());
			bullet->SetOwner(_object);
			bullet->SetSpeed(5);

			((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);

		}

	}

}