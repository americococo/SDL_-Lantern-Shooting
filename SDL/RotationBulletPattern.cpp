#include "RotationBulletPattern.h"
#include "RotationBullet.h"
#include "GameScene.h"
#include "SceneManger.h"
#include "BulletManger.h"

#include "Enemy.h"

RotationBulletPattern::RotationBulletPattern()
{
	_AttackCoolTime = 1000 * 0.2;
}
RotationBulletPattern::~RotationBulletPattern()
{

}

void RotationBulletPattern::Update(int deltaTime)
{
	_DuractionTime += deltaTime;

	if (_DuractionTime >= _AttackCoolTime)
	{
		_DuractionTime = 0;
		if (true == angleright)
		{
			for (int i = 0; i <= 360; i += 30)
			{

				RotationBullet * bullet = new RotationBullet();

				int EnterBulletX = _object->GetPostionX();
				int EnterBulletY = _object->GetPostionY();
				bullet->Init("Bullet.csv");

				bullet->SetAngle(i);
				bullet->SetOwner(_object);
				bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);

				((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
			}
		}
		if (false == angleright)
		{
			for (int i = 15; i <= 375; i += 30)
			{
				RotationBullet * bullet = new RotationBullet();

				int EnterBulletX = _object->GetPostionX();
				int EnterBulletY = _object->GetPostionY();
				bullet->Init("Bullet.csv");

				bullet->SetAngle(i);
				bullet->SetOwner(_object);
				bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);

				((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
			}
		}
		angleright = !angleright;
	}

	_DuractionChangeTime += deltaTime;
	if (_ChangeCoolTime >= _DuractionChangeTime)
	{
		_DuractionChangeTime = 0;
		((Enemy*)_object)->ChangePattern(eBulletPattern::AIMMING);
	}
}