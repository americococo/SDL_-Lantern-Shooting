#include "IdleState.h"
#include "InputManager.h"
#include "GameObject.h"


IdleState::IdleState()
{
	_thisType = eStateType::IDLE;
}

IdleState::~IdleState()
{
}

void IdleState::Update(int deltaTime)
{
	int x = 0;
	int y = 0;

	if (InputManager::GetInstance()->IsInputKey(SDLK_LEFT))
		--x;

	if (InputManager::GetInstance()->IsInputKey(SDLK_RIGHT))
		++x;
	
	if (InputManager::GetInstance()->IsInputKey(SDLK_UP))
		--y;

	if (InputManager::GetInstance()->IsInputKey(SDLK_DOWN))
		++y;


	_object->MoveVector(x, y);

	_object->changeState(eStateType::MOVE);
}