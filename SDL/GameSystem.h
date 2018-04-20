#pragma once

struct SDL_Renderer;
struct SDL_Window;


class GameSystem
{
private:
	GameSystem();

public:
	~GameSystem();

private:
	static GameSystem* instance;
public:
	static GameSystem * Getinstance();

private:
	SDL_Renderer * _mRender;

public:
	void setRender(SDL_Renderer * SDL_IPRender);
	SDL_Renderer * GetRender();

	//window Info
private:
	int _windowW;
	int _windowH;

public:
	int GetWindowW();
	int GetWindowH();

	int GetWindowCenterX();
	int GetWindowCenterY();

	//Quit
public:
	void Quit();


};
