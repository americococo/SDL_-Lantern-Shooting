#include "IdleState.h"
#include "InputManager.h"
#include "GameObject.h"
#include "PlayerobcaleCal.h"

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
		(_object)->MoveVector(--x,y);

	 if (InputManager::GetInstance()->IsInputKey(SDLK_RIGHT))
		(_object)->MoveVector(++x, y);
	
	if (InputManager::GetInstance()->IsInputKey(SDLK_UP))
		(_object)->MoveVector(x, --y);

	if (InputManager::GetInstance()->IsInputKey(SDLK_DOWN))
		(_object)->MoveVector(x, ++y);

	((PlayerObcaleCal*)(_object))->changeState(eStateType::MOVE);
}