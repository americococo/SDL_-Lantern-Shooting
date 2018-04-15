#pragma once
#include "BulletPattern.h"
class RotationBulletPattern : public BulletPattern
{
public:
	RotationBulletPattern();
	~RotationBulletPattern();


	void Update(int deltaTime);

private:
	bool angleright = true;
};
