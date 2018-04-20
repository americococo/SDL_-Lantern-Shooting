#pragma once
#include <map>
#include <SDL.h>
class InputManager
{
private:
	InputManager();
	static InputManager * _instance;
public:
	~InputManager();
	static InputManager * GetInstance();


private:
	std::map<int, bool> _input;

public:
	void KeyUp(int code);
	void KeyDown(int code);

	bool IsInputKey(int code);
};
