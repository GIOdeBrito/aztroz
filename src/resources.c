#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "global.h"
#include "resources.h"
#include "window.h"

SDL_Texture* sprites[MAX_TEXTURES];

void LoadSprites (void)
{
	char _sprites[][20] = {
		"data/ship.png",
		"data/meteor.png"
	};

	for(int i = 0; i < LENGTH(_sprites); i++)
	{
		SDL_Texture* _texture = IMG_LoadTexture(GetRenderer(), _sprites[i]);

		if(_texture == NULL)
		{
			printf("Failed to load: %s\n", _sprites[i]);
			continue;
		}

		sprites[i] = _texture;
	}
}

void UnloadSprites (void)
{
	size_t len = LENGTH(sprites);

	for(int i = 0; i < len; i++)
	{
		if(sprites[i] == NULL)
		{
			continue;
		}

		SDL_DestroyTexture(sprites[i]);
		printf("Free'd sprite at INDEX %d\n", i);
	}
}

SDL_Texture* GetSprite (int i)
{
	return sprites[i];
}
