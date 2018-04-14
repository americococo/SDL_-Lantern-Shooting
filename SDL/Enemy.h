#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();


	void Init(const char * name);
	void DeInit();
	void Render();
	void Update(int deltaTime);
private:
	int _AttackCoolTime;
	int _DuractionTime ;

public:
	void Attack();
private:
	bool angleright;
};

