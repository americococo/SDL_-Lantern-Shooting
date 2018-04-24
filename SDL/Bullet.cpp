#include "Bullet.h"
#include "BulletManger.h"
#include "GameScene.h"
#include "SceneManger.h"
#include "GameObjectManger.h"
#include "GameSystem.h"
#include "PlayerobcaleCal.h"
#include "Sprite.h"
#include <map>
#include <stdio.h>
Bullet::Bullet():GameObject()
{

}

Bullet::~Bullet()
{
}

void Bullet::Init(const char * name)
{
	_sprite = new Sprite(name, true);
}

void Bullet::EnterBulletPosition(int EnterPositionX, int EnterPositionY)
{
	_EnterBulletPositionX = EnterPositionX;
	_EnterBulletPositionY = EnterPositionY;

	_x = _EnterBulletPositionX;
	_y = _EnterBulletPositionY;
}
void Bullet::DeInit()
{
	GameObject::DeInit();
}

void Bullet::Render()
{
	if (_isLive == false)
		return;

	GameObject::Render();
}

void Bullet::Update(int deltaTime)
{
	if (_isLive == false)
		return;

	GameObject::Update(deltaTime);

	MoveBullet();
	
	std::map<std::wstring, GameObject*>::iterator itr = ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetBegin();

	for (itr; itr != ((GameScene*)SceneManger::Getinstance()->GetScene())->GetObjectManger()->GetEnd(); itr++)
	{
		if (GetOwner() != itr->second)
		{

			if (_minX<	itr->second->GetPostionMaxX() &&
				_minY <	itr->second->GetPostionMaxY() &&
				_maxX	>	itr->second->GetPostionMinX() &&
				_maxY >itr->second->GetPostionMaxY())
			{
				_isLive = false;
				itr->second->Damage();

			}

		}
	}

	if (false == CheckOutscreen())
		_isLive = false;

}
void Bullet::SetOwner(GameObject * object)
{
	_Owner = object;
}
GameObject * Bullet::GetOwner()
{
	return _Owner;
}
void Bullet::MoveBullet()
{
	_y += _speed;
}
void Bullet::SetSpeed(int speed)
{
	_speed = speed;
}

bool Bullet::CheckOutscreen()
{
	if(_x >= GameSystem::Getinstance()->GetGameScreenLeft() && _x <= GameSystem::Getinstance()->GetGameScreenRight()
		&& _y >= GameSystem::Getinstance()->GetGameScreenTop() && _y <= GameSystem::Getinstance()->GetGameScreenBottom())
		return true;
	return false;
}