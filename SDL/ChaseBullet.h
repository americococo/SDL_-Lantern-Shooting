#pragma once
#include "Bullet.h"
class GameObject;

class ChaseBullet :public Bullet
{
public:
	ChaseBullet();
	~ChaseBullet();
	void Init(const char * name);
	void Update(int deltaTime);

	void SetTarget(GameObject * object);
	void MoveBullet();
private:
	GameObject * _target;
	float _theta;

	float _MoveVectorX;
	float _MoveVectorY;
};
