#include <stdio.h>
#include <SDL2/SDL.h>
#include "global.h"
#include "player.h"
#include "hazard.h"
#include "controller.h"
#include "window.h"
#include "text.h"

void GameLoop (void)
{
	InstantiatePlayer();

	InitText();
	InitHazards();

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

		DetectController(event);

		// Clear the screen
		SDL_RenderClear(GetRenderer());

		// Draws text on the screen
		DrawOnScreenText();

		UpdatePlayer(event);
		UpdateMeteors();

		// Draws the screen
		SDL_RenderPresent(GetRenderer());

		// Clears screen text
		ClearOnScreenText();
	}

	DestroyFonts();
	DestroyController();
}

