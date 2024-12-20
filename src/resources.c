#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "global.h"

#define MAX_TEXTURES 64

SDL_Texture* textures[MAX_TEXTURES];

void LoadTextures (SDL_Renderer* renderer)
{
	char sprites[][20] = {
		"graphics/ship.png",
		"graphics/meteor.png"
	};

	for(int i = 0; i < LENGTH(sprites); i++)
	{
		SDL_Texture* _texture = IMG_LoadTexture(renderer, sprites[i]);

		if(_texture == NULL)
		{
			printf("Failed to load: %s\n", sprites[i]);
			continue;
		}

		textures[i] = _texture;
	}
}

void UnloadTextures (void)
{
	size_t len = LENGTH(textures);

	for(int i = 0; i < len; i++)
	{
		if(textures[i] == NULL)
		{
			continue;
		}

		printf("Unloading sprite... INDEX = %d\n", i);
		SDL_DestroyTexture(textures[i]);
	}
}

SDL_Texture* UseTexture (int i)
{
	return textures[i];
}
