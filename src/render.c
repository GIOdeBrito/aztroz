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
        .pivot = { player.rect.w / 2, player.rect.h / 2 },
	};

	const int meteor_max_number = 6;

	meteor_t meteors[meteor_max_number];

	for(int i = 0; i < meteor_max_number; i++)
	{
		meteors[i] = (meteor_t) {
			.sz = 32,
			.angle = 0,
			.rect = { .x = 30, .y = 30, .w = 32, .h = 32 },
			.pivot = { 32 / 2, 32 / 2 }
		};
	}

	printf("METEOR LENGTH: %ld\n", LENGTH(meteors));

	while(true)
	{
		SDL_Event event;

		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) break;
		}

		control_player(event, &player);

		SDL_RenderClear(renderer);

		// Renders player
		SDL_RenderCopyExF(renderer, UseTexture(0), NULL, &player.rect, player.angle, &player.pivot, SDL_FLIP_NONE);

		RenderMeteors(meteors, LENGTH(meteors), renderer);

		SDL_RenderPresent(renderer);
	}
}

void RenderMeteors (meteor_t* meteors, size_t length, SDL_Renderer* renderer)
{
	for(int i = 0; i < length; i++)
	{
		//printf("%1.2f\n", &meteors[i].rect.x);

		SDL_RenderCopyExF(renderer, UseTexture(1), NULL, &meteors[i].rect, meteors[i].angle, &meteors[i].pivot, SDL_FLIP_NONE);
	}
}

