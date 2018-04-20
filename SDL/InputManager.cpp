#include "InputManager.h"
InputManager::InputManager()
{
	
}

InputManager::~InputManager()
{
}
InputManager * InputManager::_instance = nullptr;

InputManager * InputManager::GetInstance()
{
	if (nullptr == _instance)
	{
		_instance = new InputManager();
	}
	return _instance;
}

void  InputManager::KeyUp(int code) 
{
	_input[code] = false;
}
void InputManager::KeyDown(int code)
{
	_input[code] = true;
}

bool InputManager::IsInputKey(int code)
{
	return _input[code];
}

