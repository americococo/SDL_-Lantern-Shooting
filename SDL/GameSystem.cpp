#include <SDL.h>
#include "GameSystem.h"

GameSystem* GameSystem::instance = nullptr;

GameSystem* GameSystem::Getinstance()
{
	if (nullptr == instance)
		instance = new GameSystem();

	return instance;
}


GameSystem::GameSystem()
{
	_windowW = 1024;
	_windowH = 800;

	_screenLeft = 0 + 50;
	_screenRight = _windowW - 50;

	_screenTop = 0 + 50;
	_screenBottom = _windowH - 50;
}

GameSystem::~GameSystem()
{
	delete instance;
}



void GameSystem::setRender(SDL_Renderer* SDL_IPRender)
{
	_mRender = SDL_IPRender;
}

SDL_Renderer * GameSystem::GetRender()
{
	return _mRender;
}

int GameSystem::GetWindowW()
{
	return _windowW;
}

int GameSystem::GetWindowH()
{
	return _windowH;
}

int GameSystem::GetWindowCenterX()
{
	return _windowW / 2;
}

int GameSystem::GetWindowCenterY()
{
	return _windowH / 2;
}

void GameSystem::Quit()
{
	SDL_Event quitEvent;
	quitEvent.type = SDL_QUIT;
	SDL_PushEvent(&quitEvent);
}
