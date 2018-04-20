#pragma once
#include "BulletPattern.h"
class ChaseBulletPattern : public BulletPattern
{
public:
	ChaseBulletPattern(int AttackCoolTime);
	~ChaseBulletPattern();


	void Update(int deltaTime);

private:
	bool angleright = true;
};
