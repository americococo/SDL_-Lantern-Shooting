#pragma once
#include "BulletPattern.h"
class AimmingBulletPattern : public BulletPattern
{
public:
	AimmingBulletPattern(int AttackCoolTime);
	~AimmingBulletPattern();


	void Update(int deltaTime);

private:
	bool angleright = true;

	int RestStart;
	int RestEnd;
	int RestDuractionTIme;
	int RestTime;
};
