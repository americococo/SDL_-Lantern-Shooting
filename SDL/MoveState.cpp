#include "MoveState.h"
#include "GameObject.h"

MoveState::MoveState()
{
	_thisType = eStateType::MOVE;
}

MoveState::~MoveState()
{
}
void MoveState::Update(int deltaTime) 
{
	int positionX = _object->GetPostionX();
	int positionY = _object->GetPostionY();
	

	positionX += _object->GetMoveVectorX() * _object->GetSpeed();
	positionY += _object->GetMoveVectorY() * _object->GetSpeed();

	_object->SetPostion(positionX, positionY);

	_object->ResetMoveVector();

	(_object)->changeState(eStateType::IDLE);
}