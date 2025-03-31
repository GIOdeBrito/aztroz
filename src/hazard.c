#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "global.h"
#include "hazard.h"
#include "resources.h"
#include "window.h"

meteor_t meteors[METEOR_MAX_NUMBER] = {0};

void InitHazards (void)
{
	for(int i = 0; i < METEOR_MAX_NUMBER; i++)
	{
		meteors[i] = (meteor_t) {
			.sz = 32,
			.angle = rand() % 360,
			.rect = {
				.x = -32.0,
				.y = rand() % SCREEN_Y,
				.w = 32,
				.h = 32
			},
			.pivot = { 32 / 2, 32 / 2 }
		};
	}
}

void UpdateMeteors (void)
{
	int length = LENGTH(meteors);

	for(int i = 0; i < length; i++)
	{
		meteors[i].angle += 0.85 * METEOR_ROTATION_SPEED;
		meteors[i].rect.x += 0.35 * METEOR_TRANSFORM_SPEED;

		SDL_RenderCopyExF(
			GetRenderer(),
			GetSprite(1),
			NULL,
			&meteors[i].rect,
			meteors[i].angle,
			&meteors[i].pivot,
			SDL_FLIP_NONE
		);

		if(meteors[i].rect.x < (double) SCREEN_X)
		{
			continue;
		}

		meteors[i].rect.x = -64.0;
		meteors[i].rect.y = (double) RandRange(1, SCREEN_Y);
	}
}

