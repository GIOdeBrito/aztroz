#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "global.h"

int key_player_direction = -1;
int move_player = -1;

void control_player (SDL_Event event, player_t* player)
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

	// Esquerda
	if(key_player_direction == 1)
	{
		player->angle += PLAYER_ROTATION * PLAYER_ROTATION_MULT;
	}
	// Direita
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

	// Mover nave
	if(move_player == 1)
	{
		float radians = GRATORAD(player->angle);
		double dX = cos(radians) * .03;
		double dY = sin(radians) * .03;
		player->rect.x += dX;
		player->rect.y += dY;
	}
}
