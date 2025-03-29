#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "global.h"

SDL_GameController* gameController = NULL;

int main (void)
{
	printf("Initializing...\n");

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0)
	{
		printf("Failed to start SDL");
		return -1;
	}

	TTF_Init();

	SDL_Window* window = CreateAztrozWindow();
	SDL_Renderer* renderer = CreateAztrozRenderer(window);

	gameController = SDL_GameControllerOpen(0);

	if(gameController)
	{
		printf("Connected controller %s", SDL_GameControllerName(gameController));
	}

	LoadTextures(renderer);

	// Starts the main game loop
	GameLoop(window, renderer);

	printf("Shutting down...\n");

	UnloadTextures();

	if(gameController != NULL)
	{
		SDL_GameControllerClose(gameController);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}
