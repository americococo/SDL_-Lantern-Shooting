#include "AimmingBulletPattern.h"
#include "GameScene.h"
#include "SceneManger.h"
#include "BulletManger.h"
#include "GameObjectManger.h"
#include "GameObject.h"


#include "aimingBullet.h"
#include "Enemy.h"
#include <map>
AimmingBulletPattern::AimmingBulletPattern(int AttackCoolTime):BulletPattern(AttackCoolTime)
{
	RestStart = 0;
	RestEnd = 2000;
	RestDuractionTIme = 0;
	RestTime = 5000/2;
}
AimmingBulletPattern::~AimmingBulletPattern() {}
void AimmingBulletPattern::Update(int deltaTime)
{
	_DuractionTime += deltaTime;
	RestDuractionTIme += deltaTime;

	if (_DuractionTime >= _AttackCoolTime &&  RestDuractionTIme >=RestTime)
	{
		_DuractionTime = 0;
		RestDuractionTIme = 0;

		std::map<std::wstring, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();

		for (itr; itr != ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetEnd(); itr++)
		{
			switch (itr->second->GetObjectType())
			{
			case eObjectType::Player:

				aimingBullet * bullet = new aimingBullet();
				int EnterBulletX = _object->GetPostionX();
				int EnterBulletY = _object->GetPostionY();
				bullet->Init("Bullet.csv");
				bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
				bullet->SetOwner(_object);
				bullet->SetTargetPosition(itr->second->GetPostionX(), itr->second->GetPostionY());
				bullet->SetSpeed(15);
				((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
				break;
			}
		}
	}
	else
	{
		
	}
	
}