#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "global.h"
#include "controller.h"

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

	TTF_Font *font = TTF_OpenFont("graphics/roboto.ttf", 24);

	Uint32 lastTime = 0, currentTime;
    int frameCount = 0;
    float fps = 0;

	while(true)
	{
		SDL_Event event;

		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) break;
		}

		DetectController();

		// Clear the screen
		SDL_RenderClear(renderer);

		// Fps counter

		// Calculate FPS
        currentTime = SDL_GetTicks();
        frameCount++;

        if (currentTime > lastTime + 1000) {
            fps = frameCount * 1000.0f / (currentTime - lastTime);
            lastTime = currentTime;
            frameCount = 0;
        }

        // Convert FPS to string
        char fpsText[16];
        sprintf(fpsText, "FPS: %.2f", fps);

		SDL_Color textColor = {255, 255, 255, 255};

		SDL_Surface *textSurface = TTF_RenderText_Solid(font, fpsText, textColor);
	    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_Rect textRect = {100, 100, textSurface->w, textSurface->h};

		PlayerController(event, &player);
		MeteorController(meteors, LENGTH(meteors), renderer);

		// Renders player
		SDL_RenderCopyExF(renderer, GetSprite(0), NULL, &player.rect, player.angle, &player.pivot, SDL_FLIP_NONE);

		// Renders text
		SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

		SDL_RenderPresent(renderer);

		SDL_FreeSurface(textSurface);
	    SDL_DestroyTexture(textTexture);
	}

	TTF_CloseFont(font);
	DestroyController();
}

void RenderFPSOnScreen (SDL_Renderer* renderer)
{

}

