#pragma once
#include "State.h"
class MonsterIdleState :public State
{
public:
	MonsterIdleState();
	~MonsterIdleState();

	void Update(int deltaTime);

private:
	int posx;
	int posy;


};
