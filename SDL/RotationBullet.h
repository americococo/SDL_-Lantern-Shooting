#pragma once
#include "Bullet.h"

class RotationBullet :public Bullet
{
public:
	RotationBullet();
	~RotationBullet();


	void Init(const char * name);
	void Update(int deltaTime);
	void MoveBullet();
public:
	void SetAngle(int angle);

private:
	
	int _angle;
	int _distance;

public:
	void SetBullet();

};

