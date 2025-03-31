#include <stdio.h>
#include <SDL2/SDL.h>
#include "global.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int win_X = 0;
int win_Y = 0;

int InitWindow (void)
{
	window = SDL_CreateWindow(PROJECT,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_X,SCREEN_Y,SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		printf("Was not able to create game window\n");
		SDL_DestroyWindow(window);
		exit(-1);
	}

	SDL_GetWindowSize(window, &win_X, &win_Y);

	return 0;
}

int InitRenderer (void)
{
	if(window == NULL)
	{
		printf("Window must be created before renderer\n");
		exit(-1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(renderer == NULL)
	{
		printf("Was not able to create SDL renderer\n");
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		exit(-1);
	}

	return 0;
}

SDL_Window* GetWindow (void)
{
	return window;
}

SDL_Renderer* GetRenderer (void)
{
	return renderer;
}

int GetWindowX (void)
{
	return win_X;
}

int GetWindowY (void)
{
	return win_Y;
}

void DestroyWindow (void)
{
	SDL_DestroyWindow(window);
}

void DestroyRenderer (void)
{
	SDL_DestroyRenderer(renderer);
}
