#include "RotationBullet.h"
#include <map>

#include "GameSystem.h"
#include "GameObject.h"

#include "SceneManger.h"
#include "GameScene.h"
#include "GameObjectManger.h"
#include "SceneManger.h"
#include <math.h> 
RotationBullet::RotationBullet()
{

}

RotationBullet::~RotationBullet()
{
}
void RotationBullet::Init(const char * name)
{
	Bullet::Init(name);
	_distance = 100;
}
void RotationBullet::SetAngle(int angle)
{
	_angle = angle;
}

void RotationBullet::Update(int deltaTime)
{
	if (_isLive == false)
		return;

	Bullet::Update(deltaTime);

}
void RotationBullet::MoveBullet()
{
	_distance += 5;
	SetBullet();
}
void RotationBullet::EnterBulletPosition(int EnterPositionX, int EnterPositionY)
{
	_EnterBulletPositionX = EnterPositionX;
	_EnterBulletPositionY = EnterPositionY;
}

void RotationBullet::SetBullet()
{
	float radian = _angle * 3.141592 / 180;

	_x = _distance * sin(radian) + _EnterBulletPositionX;
	_y = _distance * cos(radian) + _EnterBulletPositionY;
}
