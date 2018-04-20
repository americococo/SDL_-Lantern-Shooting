#pragma once
#include "Bullet.h"

class aimingBullet :public Bullet
{
public:
	aimingBullet();
	~aimingBullet();


	void Init(const char * name);
	void Update(int deltaTime);
	
	void MoveBullet();

	void SetTargetPosition(int targetX, int targetY);
private:
	int _targetX, _targetY;
};
