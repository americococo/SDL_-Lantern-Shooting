#pragma once

class GameObject;

class BulletPattern
{
public:
	BulletPattern(int AttackCoolTime);
	~BulletPattern();

	void Init(GameObject * object);
	virtual void Update(int deltaTime);
protected:
	GameObject * _object;


	int _DuractionTime;

	int _AttackCoolTime;

	
	
};
