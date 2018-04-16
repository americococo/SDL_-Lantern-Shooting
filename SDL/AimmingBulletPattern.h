#pragma once
#include "BulletPattern.h"
class AimmingBulletPattern : public BulletPattern
{
public:
	AimmingBulletPattern();
	~AimmingBulletPattern();


	void Update(int deltaTime);

private:
	bool angleright = true;
};
