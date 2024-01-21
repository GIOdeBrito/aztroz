#include <stdio.h>
#include <SDL2/SDL.h>
#include "global.h"

SDL_Renderer* CreateAztrozRenderer (SDL_Window* win)
{
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL)
	{
		printf("Was not able to create SDL renderer");
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(renderer);
		exit(-1);
	}

	return renderer;
}

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

	while(true)
	{
		SDL_Event event;

		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				break;
		}

		control_player(event, &player);

		// Limpa a tela
		SDL_RenderClear(renderer);

		// Renderiza o jogador
		SDL_RenderCopyExF(renderer, UseTexture(0), NULL, &player.rect, player.angle, &player.pivot, SDL_FLIP_NONE);

		// Mostra tudo a ser renderizado
		SDL_RenderPresent(renderer);
	}
}
