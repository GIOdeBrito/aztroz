#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "global.h"
#include "player.h"
#include "resources.h"
#include "window.h"

int key_player_direction = -1;
int move_player = -1;

player_t player = {0};

void InstantiatePlayer (void)
{
	player = (player_t) {
	    .sz = PLAYER_SIZE,
        .angle = -90,
		.rect = { .x = GetWindowX() / 2, .y = GetWindowY() / 2, .w = PLAYER_SIZE, .h = PLAYER_SIZE }
	};

	player.pivot.x = player.rect.w / 2;
	player.pivot.y = player.rect.h / 2;
}

void UpdatePlayer (SDL_Event event)
{
	PlayerController(event);

	// Renders the player on-screen
	SDL_RenderCopyExF(
		GetRenderer(),
		GetSprite(0),
		NULL,
		&player.rect,
		player.angle,
		&player.pivot,
		SDL_FLIP_NONE
	);
}

int GetPlayerPosX (void)
{
	return player.rect.x;
}

int GetPlayerPosY (void)
{
	return player.rect.y;
}

int GetPlayerAngle (void)
{
	return abs(player.angle);
}

void PlayerController (SDL_Event event)
{
	PlayerMoveKeyboard(event);
	PlayerMoveGamepad(event);

	// Left
	if(key_player_direction == 1)
	{
		player.angle += PLAYER_ROTATION * PLAYER_ROTATION_MULT;
	}
	// Right
	else if(key_player_direction == 2)
	{
		player.angle -= PLAYER_ROTATION * PLAYER_ROTATION_MULT;
	}

	if(player.angle > 360.0f)
	{
		player.angle = 0.0f;
	}
	else if(player.angle < -360.0f)
	{
		player.angle = 0.0f;
	}

	// Move player ship
	if(move_player != 1)
	{
		return;
	}

	float radians = GRATORAD(player.angle);
	double dX = cos(radians) * 2;
	double dY = sin(radians) * 2;

	player.rect.x += dX;
	player.rect.y += dY;
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
