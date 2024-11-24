// how to make bit-fields and bit-masks work in the real world...
// prog71990 - fall 2024 - professor steveh
//
// a program I am working on uses SDL2 for graphics.  It has an SDL_Init() method
// described here:
// https://wiki.libsdl.org/SDL_Init

#include "graphics.h"
#include <stdio.h>

void InitializeGraphics(INIT_VALUES bitmask)
{
	if ((bitmask & SDL_INIT_TIMER) == SDL_INIT_TIMER)
		printf("option timer has been selected\n");

	if ((bitmask & SDL_INIT_AUDIO) == SDL_INIT_AUDIO)
		printf("option audio has been selected\n");

	if ((bitmask & SDL_INIT_VIDEO) == SDL_INIT_VIDEO)
		printf("option video has been selected\n");

	if ((bitmask & SDL_INIT_JOYSTICK) == SDL_INIT_JOYSTICK)
		printf("option joystick has been selected\n");

	if ((bitmask & SDL_INIT_HAPTIC) == SDL_INIT_HAPTIC)
		printf("option haptic has been selected\n");

	if ((bitmask & SDL_INIT_GAMECONTROLLER) == SDL_INIT_GAMECONTROLLER)
		printf("option gamecontroller has been selected\n");

	if ((bitmask & SDL_INIT_EVENTS) == SDL_INIT_EVENTS)
		printf("option events has been selected\n");
}
