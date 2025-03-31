#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "global.h"
#include "player.h"
#include "window.h"
#include "text.h"

Uint32 lastTime = 0, currentTime;
int frameCount = 0;
float fps = 0;

TTF_Font* roboto24 = NULL;
TTF_Font* roboto12 = NULL;

text_t textObjects[MAX_TEXT_ONSCREEN] = {0};

void InitText (void)
{
	roboto24 = TTF_OpenFont("graphics/roboto.ttf", 24);
	roboto12 = TTF_OpenFont("graphics/roboto.ttf", 12);
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

void QueueText (char* text, int x, int y, TTF_Font* font)
{
	SDL_Color textColor = { 255, 255, 255, 255 };

	SDL_Surface* textSurface = TTF_RenderText_Solid(roboto12, text, textColor);
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

	QueueText(fpsText, 0, 0, NULL);
}

void DrawPlayerPosition(void)
{
	char pos[32];
	sprintf(pos, "X: %d | Y: %d", PlayerPosX(), PlayerPosY());

	QueueText(pos, 0, 20, NULL);
}

void DestroyFonts (void)
{
	TTF_CloseFont(roboto24);
	TTF_CloseFont(roboto12);
}

