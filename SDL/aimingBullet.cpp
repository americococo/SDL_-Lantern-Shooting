#include "aimingBullet.h"
#include <math.h>

aimingBullet::aimingBullet()
{
}

aimingBullet::~aimingBullet()
{
}


void aimingBullet::Init(const char * name) 
{
	Bullet::Init(name);
}
void aimingBullet::Update(int deltaTime) 
{
	Bullet::Update(deltaTime);
}


void aimingBullet::MoveBullet()
{
	float distanceX = _targetX - _EnterBulletPositionX;
	float distanceY = _targetY - _EnterBulletPositionY;

	float distance = sqrt(distanceX*distanceX + distanceY * distanceY);

	int vectorX = distanceX / distance * _speed;
	int vectorY = distanceY / distance * _speed;


	_x += vectorX;
	_y += vectorY;
}

void aimingBullet::SetTargetPosition(int targetX, int targetY)
{
	_targetX = targetX;
	_targetY = targetY;
}