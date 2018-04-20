#include "State.h"
State::State() {}
State:: ~State() {}


void State::Init(GameObject * object) 
{
	_object = object;
}
void State::Start() {}
void State::Update(int deltaTime) {}
void State::Stop() {}
