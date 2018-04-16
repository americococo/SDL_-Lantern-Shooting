#include "AimmingBulletPattern.h"
#include "GameScene.h"
#include "SceneManger.h"
#include "BulletManger.h"
#include "GameObjectManger.h"
#include "GameObject.h"


#include "aimingBullet.h"
#include "Enemy.h"
#include <map>
AimmingBulletPattern::AimmingBulletPattern() 
{
	_AttackCoolTime = 1000 ;
}
AimmingBulletPattern::~AimmingBulletPattern() {}
void AimmingBulletPattern::Update(int deltaTime)
{
	_DuractionTime += deltaTime;

	if (_DuractionTime >= _AttackCoolTime)
	{
		_DuractionTime = 0;
		std::map<int, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();

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
				bullet->SetSpeed(5);
				((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
				break;
			}
		}
	}

	_DuractionChangeTime += deltaTime;
	if (_ChangeCoolTime >= _DuractionChangeTime)
	{
		_DuractionChangeTime = 0;
		((Enemy*)_object)->ChangePattern(eBulletPattern::CHASE);
	}
}