#include <stdio.h>
#include <SDL2/SDL.h>

SDL_GameController* gameController = NULL;

void DetectController (void)
{
	if(gameController != NULL)
	{
		return;
	}

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

	printf("Destroying controller: %s\n", SDL_GameControllerName(gameController));

	SDL_GameControllerClose(gameController);
}
