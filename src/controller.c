#include <stdio.h>
#include <SDL2/SDL.h>
#include "controller.h"

SDL_GameController* gameController = NULL;

void DetectController (SDL_Event event)
{
	if(event.type == SDL_JOYDEVICEREMOVED)
	{
		DestroyController();
		return;
	}

	if(event.type != SDL_JOYDEVICEADDED)
	{
		return;
	}

	AddController();
}

void AddController (void)
{
	DestroyController();

	gameController = SDL_GameControllerOpen(0);

	if(gameController == NULL)
	{
		return;
	}

	printf("Controller connected: %s\n", SDL_GameControllerName(gameController));
}

void DestroyController (void)
{
	if(gameController == NULL)
	{
		return;
	}

	printf("Free'd controller: %s\n", SDL_GameControllerName(gameController));

	SDL_GameControllerClose(gameController);
	gameController = NULL;
}
