#pragma once


#include <list>
class Bullet;

class BulletManger
{
public:
	BulletManger();
	~BulletManger();

private:
	std::list <Bullet*> _bulletList;

public:
	void pushBulletList(Bullet* bullet);
	
	Bullet * GetBulletListBack();
	void Update(int deltaTime);
	void Render();


	void DeInit();

};
