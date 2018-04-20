#include <SDL.h>
#include <SDL_main.h>

#include "GameSystem.h"
#include "SceneManger.h"
#include "InputManager.h"

int main(int argc,char * argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window * SDL_win = SDL_CreateWindow("Lantern Shooting Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		GameSystem::Getinstance()->GetWindowW(), 
		GameSystem::Getinstance()->GetWindowH(),
		SDL_WINDOW_OPENGL);


	
	GameSystem::Getinstance()->setRender(SDL_CreateRenderer(SDL_win, -1, 0));

	SceneManger::Getinstance()->ChangeScene(eSceneType::TITLE);

	SDL_SetRenderDrawColor(GameSystem::Getinstance()->GetRender(), 255, 255, 255, 255);


	SDL_Event Event;

	int frame = 0, oldFrame = 0;
	int curtick = SDL_GetTicks();
	int oldTick = curtick;

	while (1)
	{
		curtick = SDL_GetTicks();//

		frame = (SDL_GetTicks() % 1000) * 60;

		frame /= 1000;

		if (oldFrame != frame)
		{
			oldFrame = frame;

			int deltaTime = curtick - oldTick;
			oldTick = curtick;

			if (SDL_PollEvent(&Event))
			{
				if (SDL_QUIT == Event.type)
					break;

				if (SDL_KEYUP == Event.type)
				{
					if (Event.key.keysym.sym == SDLK_ESCAPE)
					{
						SDL_Event quitEvent;
						quitEvent.type = SDL_QUIT;
						SDL_PushEvent(&quitEvent);
					}
					InputManager::GetInstance()->KeyUp(Event.key.keysym.sym);
				}

				if (SDL_KEYDOWN == Event.type)
				{
					InputManager::GetInstance()->KeyDown(Event.key.keysym.sym);
					// SceneManger::Getinstance()->keyDown(Event.key.keysym.sym);
				}
			}

			

			SceneManger::Getinstance()->Update(deltaTime);

			SDL_RenderClear(GameSystem::Getinstance()->GetRender());
			{
				SceneManger::Getinstance()->Render();
			}

			SDL_RenderPresent(GameSystem::Getinstance()->GetRender());
		}
	}

	SDL_DestroyRenderer(GameSystem::Getinstance()->GetRender());


	return 0;
}