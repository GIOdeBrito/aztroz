#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "global.h"

int key_player_direction = -1;
int move_player = -1;

void PlayerController (SDL_Event event, player_t* player)
{
	PlayerMoveKeyboard(event);
	PlayerMoveGamepad(event);

	// Left
	if(key_player_direction == 1)
	{
		player->angle += PLAYER_ROTATION * PLAYER_ROTATION_MULT;
	}
	// Right
	else if(key_player_direction == 2)
	{
		player->angle -= PLAYER_ROTATION * PLAYER_ROTATION_MULT;
	}

	if(player->angle > 360.0f)
	{
		player->angle = 0.0f;
	}
	else if(player->angle < -360.0f)
	{
		player->angle = 0.0f;
	}

	// Move player ship
	if(move_player == 1)
	{
		float radians = GRATORAD(player->angle);
		double dX = cos(radians) * 2;
		double dY = sin(radians) * 2;

		player->rect.x += dX;
		player->rect.y += dY;
	}
}

void PlayerMoveKeyboard (SDL_Event event)
{
	if(event.type == SDL_KEYDOWN)
	{
		if(event.key.keysym.sym == SDLK_LEFT)
		{
			key_player_direction = 1;
		}
		else if(event.key.keysym.sym == SDLK_RIGHT)
		{
			key_player_direction = 2;
		}
		if(event.key.keysym.sym == SDLK_UP)
		{
			move_player = 1;
		}
	}
	else if(event.type == SDL_KEYUP)
	{
		if(event.key.keysym.sym == SDLK_LEFT
		|| event.key.keysym.sym == SDLK_RIGHT)
		{
			key_player_direction = -1;
		}

		if(event.key.keysym.sym == SDLK_UP)
		{
			move_player = -1;
		}
	}
}

void PlayerMoveGamepad (SDL_Event event)
{
	if(event.type == SDL_CONTROLLERBUTTONDOWN)
	{
		printf("BUTTON DOWN DPAD\n");

		if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT)
		{
			key_player_direction = 1;
		}
		else if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
		{
			key_player_direction = 2;
		}
		if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP)
		{
			move_player = 1;
		}
	}
	else if(event.type == SDL_CONTROLLERBUTTONUP)
	{
		if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT
		|| event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
		{
			key_player_direction = -1;
		}

		if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP)
		{
			move_player = -1;
		}
	}
}

void MeteorController (meteor_t* meteors, size_t length, SDL_Renderer* renderer)
{
	for(int i = 0; i < length; i++)
	{
		meteor_t* meteor = &meteors[i];

		meteor->angle += 0.85 * METEOR_ROTATION_SPEED;
		meteor->rect.x += 0.35 * METEOR_TRANSFORM_SPEED;

		SDL_RenderCopyExF(
			renderer,
			UseTexture(1),
			NULL,
			&meteor->rect,
			meteor->angle,
			&meteor->pivot,
			SDL_FLIP_NONE
		);

		if(meteor->rect.x > (double) SCREEN_X)
		{
			meteor->rect.x = 0.0;
			meteor->rect.y = (double) RandRange(1, SCREEN_Y);
		}
	}
}

