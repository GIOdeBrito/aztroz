#include <stdio.h>
#include <SDL2/SDL.h>
#include "global.h"

void GameLoop (SDL_Window* window, SDL_Renderer* renderer)
{
	int win_X = 0;
	int win_Y = 0;

	SDL_GetWindowSize(window, &win_X, &win_Y);

	player_t player = {
	    .sz = PLAYER_SIZE,
        .angle = -90,
        .rect = { .x = win_X / 2, .y = win_Y / 2, .w = player.sz, .h = player.sz },
        .pivot = { player.rect.w / 2, player.rect.h / 2 }
	};

	const int METEOR_MAX_NUMBER = 6;

	meteor_t meteors[METEOR_MAX_NUMBER];

	for(int i = 0; i < METEOR_MAX_NUMBER; i++)
	{
		meteors[i] = (meteor_t) {
			.sz = 32,
			.angle = 0,
			.rect = { .x = 30, .y = 30, .w = 32, .h = 32 },
			.pivot = { 32 / 2, 32 / 2 }
		};
	}

	while(true)
	{
		SDL_Event event;

		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) break;
		}

		// Clear the screen
		SDL_RenderClear(renderer);

		PlayerController(event, &player);
		MeteorController(meteors, LENGTH(meteors), renderer);

		// Renders player
		SDL_RenderCopyExF(renderer, UseTexture(0), NULL, &player.rect, player.angle, &player.pivot, SDL_FLIP_NONE);

		SDL_RenderPresent(renderer);
	}
}

