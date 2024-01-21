#include <stdio.h>
#include <SDL2/SDL.h>
#include "global.h"

SDL_Window* CreateAztrozWindow (void)
{
	SDL_Window* window = NULL;
	window = SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		printf("Was not able to create game window");
		exit(-6);
	}

	return window;
}
