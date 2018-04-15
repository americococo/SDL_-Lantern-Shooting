#pragma once
#include "BulletPattern.h"
class ChaseBulletPattern : public BulletPattern
{
public:
	ChaseBulletPattern();
	~ChaseBulletPattern();


	void Update(int deltaTime);

private:
	bool angleright = true;
};
