#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"

int RandRange (int min, int max)
{
	srand(time(0));

	int number = ((rand() % max) + min) - 1;

	return number;
}
