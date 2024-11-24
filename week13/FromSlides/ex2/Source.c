// how to make bit-fields and bit-masks work in the real world...
// prog71990 - fall 2024 - professor steveh
//
// a program I am working on uses SDL2 for graphics.  It has an SDL_Init() method
// described here:
// https://wiki.libsdl.org/SDL_Init

#include <stdio.h>
#include "graphics.h"

int main(void)
{
	INIT_VALUES myInput = SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_AUDIO;
	InitializeGraphics(myInput);

	printf("\n\n\n");


	INIT_VALUES myOtherInput = SDL_INIT_EVERYTHING;
	InitializeGraphics(myOtherInput);
}
