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
	window = SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800, 600,SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		printf("NAO PODE CRIAR A JANELA SDL");
		return -6;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL)
	{
		printf("NAO PODE CRIAR O RENDERIZADOR SDL");
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		return -8;
	}

	char img_nome[] = "graphics/ship.png";
	int win_X = 0;
	int win_Y = 0;
	SDL_GetWindowSize(window, &win_X, &win_Y);

	SDL_Texture* img = IMG_LoadTexture(renderer, "graphics/ship.png");

	player_t player = {
	    .width = PLAYER_SIZE,
	    .height = PLAYER_SIZE,
        .angle = 0,
        .rect = { .x = win_X / 2, .y = win_Y / 2, .w = player.width, .h = player.height },
        .pivot = { player.rect.w / 2, player.rect.h / 2 },
	};

	if(img == NULL)
	{
		printf("NAO PODE CARREGAR A IMAGEM: %s", img_nome);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		return -9;
	}

	while(1)
	{
		SDL_Event event;
		int keyHeld = -1;

		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) break;
			else if(event.type == SDL_KEYUP)
            {
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    break;
                }
                if(event.key.keysym.sym == SDLK_UP)
                {
                    keyHeld = -1;
                }
            }
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_LEFT)
                {
                    keyHeld = 1;
                }
                else if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    keyHeld = 2;
                }
            }
		}

		if(keyHeld == 1)
        {
            player.angle += PLAYER_ROTATION * PLAYER_ROTATION_MULT;
        }
        // Direita
        else if(keyHeld == 2)
        {
            player.angle -= PLAYER_ROTATION * PLAYER_ROTATION_MULT;
        }

		//img_angulo += .6 * 0.06;
		printf("ANGULO = %.2lf\n", player.angle);

		// Limpa a tela
		SDL_RenderClear(renderer);
		// Renderiza o jogador
		SDL_RenderCopyEx(renderer, img, NULL, &player.rect, player.angle, &player.pivot, SDL_FLIP_NONE);
		// Mostra tudo a ser renderizado
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(img);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	printf("Programa encerrado\n");

	return 0;
}
