#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "global.h"

int main (int argc, char* argv[])
{
	printf("Inicializando\n");

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		return -2;
	}

	SDL_Window* window = NULL;
	window = SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		printf("NAO PODE CRIAR A JANELA SDL");
		return -6;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL)
	{
		printf("NA~O PO^DE CRIAR O RENDERIZADOR SDL");
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		return -8;
	}

	int win_X = 0;
	int win_Y = 0;
	SDL_GetWindowSize(window, &win_X, &win_Y);

	LoadTextures(renderer);

	player_t player = {
	    .sz = PLAYER_SIZE,
        .angle = -90,
        .rect = { .x = win_X / 2, .y = win_Y / 2, .w = player.sz, .h = player.sz },
        .pivot = { player.rect.w / 2, player.rect.h / 2 },
	};

	while(1)
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

	UnloadTextures();

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	printf("Programa encerrado\n");

	return 0;
}
