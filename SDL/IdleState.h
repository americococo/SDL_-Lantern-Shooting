#pragma once
#include "State.h"
class IdleState : public State
{
public:
	IdleState();
	~IdleState();


	void Update(int deltaTime);


};

