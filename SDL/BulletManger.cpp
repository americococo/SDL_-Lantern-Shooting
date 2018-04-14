#include "BulletManger.h"
#include "Bullet.h"
#include <list>

BulletManger::BulletManger()
{
	_bulletList.clear();
}

BulletManger::~BulletManger()
{
}

void BulletManger::pushBulletList(Bullet *bullet)
{
	_bulletList.push_front(bullet);
}
	
Bullet * BulletManger::GetBulletListBack()
{
	if (_bulletList.empty())
		return nullptr;

	return _bulletList.back();

}

void BulletManger::Update(int deltaTime)
{
	while (nullptr != GetBulletListBack() && false == GetBulletListBack()->GetObjectLive())
	{
		Bullet * bullet= _bulletList.back();
		delete bullet;
		_bulletList.pop_back();
	}

	for (std::list<Bullet*>::iterator itr = _bulletList.begin(); itr != _bulletList.end(); itr++)
	{
		(*itr)->Update(deltaTime);
	}
}
void BulletManger::Render()
{
	for (std::list<Bullet*>::iterator itr = _bulletList.begin(); itr != _bulletList.end(); itr++)
	{
		(*itr)->Render();
	}
}

void BulletManger::DeInit()
{
	_bulletList.clear();
}