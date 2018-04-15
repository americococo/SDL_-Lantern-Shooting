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
	_AttackCoolTime = 1000 * 5;
}
ChaseBulletPattern::~ChaseBulletPattern() {}

void ChaseBulletPattern::Update(int deltaTime)
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
				ChaseBullet * bullet = new ChaseBullet();

				int EnterBulletX = _object->GetPostionX();
				int EnterBulletY = _object->GetPostionMaxY() + 50;
				bullet->Init("ChaseBullet.csv");
				bullet->EnterBulletPosition(EnterBulletX, EnterBulletY);
				bullet->SetTarget(itr->second);
				bullet->SetSpeed(5);

				((GameScene*)SceneManger::Getinstance()->GetScene())->GetBulletManger()->pushBulletList(bullet);
				break;
			}
		}
	}

	_DuractionTime += deltaTime;
	if (_ChangeCoolTime >= _DuractionChangeTime)
	{
		((Enemy*)_object)->ChangePattern(eBulletPattern::ROTATION);
	}
}