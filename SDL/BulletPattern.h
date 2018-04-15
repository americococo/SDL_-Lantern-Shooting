#pragma once

class GameObject;
enum eBulletPattern
{
	AIMMING,
	ROTATION,
	CHASE
};
class BulletPattern
{
public:
	BulletPattern();
	~BulletPattern();

	void Init(GameObject * object);
	virtual void Update(int deltaTime);
protected:
	GameObject * _object;


	int _DuractionTime;

	int _AttackCoolTime;

	int _ChangeCoolTime;
	int _DuractionChangeTime;
};
