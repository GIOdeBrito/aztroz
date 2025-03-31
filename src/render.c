#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "global.h"
#include "player.h"
#include "controller.h"
#include "window.h"
#include "text.h"

void GameLoop (void)
{
	InstantiatePlayer();

	InitText();

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
			if(event.type == SDL_QUIT)
			{
				break;
			}
		}

		DetectController();

		// Clear the screen
		SDL_RenderClear(GetRenderer());

		// Draws text on the screen
		DrawOnScreenText();

		UpdatePlayer(event);
		MeteorController(meteors, LENGTH(meteors), GetRenderer());

		SDL_RenderPresent(GetRenderer());

		ClearOnScreenText();
	}

	DestroyFonts();
	DestroyController();
}

