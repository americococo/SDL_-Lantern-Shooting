#pragma once
#include "State.h"
class MoveState :public State
{
public:
	MoveState();
	~MoveState();


	void Update(int deltaTime);
private:

};
