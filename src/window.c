#include <stdio.h>
#include <SDL2/SDL.h>
#include "global.h"

SDL_Window* CreateAztrozWindow (void)
{
	SDL_Window* window = NULL;
	window = SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_X,SCREEN_Y,SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		printf("Was not able to create game window");
		exit(-6);
	}

	return window;
}

SDL_Renderer* CreateAztrozRenderer (SDL_Window* win)
{
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(renderer == NULL)
	{
		printf("Was not able to create SDL renderer");
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(renderer);
		exit(-1);
	}

	return renderer;
}
