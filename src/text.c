#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "global.h"
#include "player.h"
#include "window.h"
#include "dictionary.h"
#include "text.h"

Uint32 lastTime = 0, currentTime = 0;
int frameCount = 0;
float fps = 0;

TTF_Font* fonts[MAX_LOADED_FONTS] = { NULL };
text_t textObjects[MAX_TEXT_ONSCREEN] = {0};

void InitText (void)
{
	DDictionary_t kvp[] = {
		{ "data/retro.ttf", 16 },
		{ "data/retro.ttf", 22 },
		{ "data/retro.ttf", 24 }
	};

	// Load fonts
	for(int i = 0; i < LENGTH(kvp); i++)
	{
		fonts[i] = TTF_OpenFont(kvp[i].key, kvp[i].value);
	}
}

void DrawOnScreenText (void)
{
	DrawFPS();
	DrawPlayerPosition();

	for(int i = 0; i < MAX_TEXT_ONSCREEN; i++)
	{
		// Renders text texture
		SDL_RenderCopy(GetRenderer(), textObjects[i].texture, NULL, &textObjects[i].rect);
	}
}

void ClearOnScreenText (void)
{
	for(int i = 0; i < MAX_TEXT_ONSCREEN; i++)
	{
		if(textObjects[i].texture == NULL)
		{
			continue;
		}

		SDL_DestroyTexture(textObjects[i].texture);

		textObjects[i].texture = NULL;
		textObjects[i].rect = (SDL_Rect) {0};
	}
}

void QueueText (char* text, int x, int y)
{
	SDL_Color textColor = { 255, 255, 255, 255 };

	SDL_Surface* textSurface = TTF_RenderText_Solid(fonts[0], text, textColor);
	SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(GetRenderer(), textSurface);
	SDL_FreeSurface(textSurface);

	for(int i = 0; i < MAX_TEXT_ONSCREEN; i++)
	{
		if(textObjects[i].texture != NULL)
		{
			continue;
		}

		textObjects[i].texture = textTexture;
		textObjects[i].rect = textRect;
		break;
	}
}

void DrawFPS (void)
{
	// Calculate FPS
	currentTime = SDL_GetTicks();
	frameCount++;

	if(currentTime > lastTime + 1000)
	{
		fps = frameCount * 1000.0f / (currentTime - lastTime);
		lastTime = currentTime;
		frameCount = 0;
	}

	// Convert FPS to string
	char fpsText[32];
	sprintf(fpsText, "FPS: %.2f", fps);

	QueueText(fpsText, 0, 0);
}

void DrawPlayerPosition(void)
{
	char pos[38];
	sprintf(pos, "X: %d | Y: %d | ANGLE: %d", GetPlayerPosX(), GetPlayerPosY(), GetPlayerAngle());

	QueueText(pos, 0, 20);
}

void DestroyFonts (void)
{
	for(int i = 0; i < MAX_LOADED_FONTS; i++)
	{
		if(fonts[i] == NULL)
		{
			continue;
		}

		TTF_CloseFont(fonts[i]);
		fonts[i] = NULL;

		printf("Free'd font at INDEX %d\n", i);
	}
}

