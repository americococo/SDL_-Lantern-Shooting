#include "BulletPattern.h"
#include "Bullet.h"

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

}