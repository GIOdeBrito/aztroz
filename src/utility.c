#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"

int RandRange (int min, int max)
{
	static boolean seeded = false;

	if(seeded == false)
	{
	    srand(time(0));
		seeded = true;
	}

	int number = ((rand() % max) + min) - 1;

	return number;
}
