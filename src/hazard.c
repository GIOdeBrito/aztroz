#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "global.h"
#include "resources.h"
#include "window.h"

void MeteorController (meteor_t* meteors, size_t length, SDL_Renderer* renderer)
{
	for(int i = 0; i < length; i++)
	{
		meteor_t* meteor = &meteors[i];

		meteor->angle += 0.85 * METEOR_ROTATION_SPEED;
		meteor->rect.x += 0.35 * METEOR_TRANSFORM_SPEED;

		SDL_RenderCopyExF(
			GetRenderer(),
			GetSprite(1),
			NULL,
			&meteor->rect,
			meteor->angle,
			&meteor->pivot,
			SDL_FLIP_NONE
		);

		if(meteor->rect.x < (double) SCREEN_X)
		{
			return;
		}

		meteor->rect.x = 0.0;
		meteor->rect.y = (double) RandRange(1, SCREEN_Y);
	}
}

