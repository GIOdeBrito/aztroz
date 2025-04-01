#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "global.h"
#include "window.h"
#include "resources.h"

int main (void)
{
	printf("Aztroz by Giordano de Brito\n");

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0)
	{
		printf("Failed to start SDL");
		return -1;
	}

	TTF_Init();

	InitWindow();
	InitRenderer();

	LoadSprites();

	// Starts the main game loop
	GameLoop();

	printf("Shutting down\n");

	UnloadSprites();

	DestroyRenderer();
	DestroyWindow();

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}
