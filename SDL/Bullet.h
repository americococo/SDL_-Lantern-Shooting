#pragma once

#include "GameObject.h"

class Bullet :public GameObject
{

public:
	Bullet();
	~Bullet();

	virtual void Init(const char * name);
	void DeInit();
	void Render();
	virtual void Update(int deltaTime);
	virtual void MoveBullet();

private:
	GameObject * _Owner;
public:
	void SetOwner(GameObject * object);
	GameObject * GetOwner();
protected:
	int _EnterBulletPositionX;
	int _EnterBulletPositionY;
public:
	void SetSpeed(int speed);
	void EnterBulletPosition(int EnterPositionX,int EnterPositionY);

protected:
	bool CheckOutscreen();
};
