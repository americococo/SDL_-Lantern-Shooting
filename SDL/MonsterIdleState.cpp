#include "MonsterIdleState.h"
#include "GameObject.h"
#include <time.h>
#include <stdlib.h>
MonsterIdleState::MonsterIdleState() 
{
	_thisType = eStateType::IDLE;
	posx = 0;
	posy = 0;
}
MonsterIdleState::~MonsterIdleState() {}

void MonsterIdleState::Update(int deltaTIme)
{
	{
		

		int x = 0;
		int y = 0;

		//���������� �̵�

		int angle = (rand() % 4) + 1;

		float radian = (angle*90) * 3.141592 / 180;

		x = 3 * sin(radian);
		y = 3 * cos(radian);

		_object->MoveVector(x, y);
	}
		_object->changeState(eStateType::MOVE);
	
}