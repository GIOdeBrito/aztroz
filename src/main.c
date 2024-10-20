#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "global.h"

int main (void)
{
	printf("Initializing...\n");

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Failed to start SDL");
		return -1;
	}

	SDL_Window* window = CreateAztrozWindow();
	SDL_Renderer* renderer = CreateAztrozRenderer(window);

	LoadTextures(renderer);

	// Starts the main game loop
	GameLoop(window, renderer);

	UnloadTextures();

	printf("Shutting down...\n");

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}
