#pragma once
// how to make bit-fields and bit-masks work in the real world...
// prog71990 - fall 2024 - professor steveh
//
// a program I am working on uses SDL2 for graphics.  It has an SDL_Init() method
// described here:
// https://wiki.libsdl.org/SDL_Init


typedef enum init_values
{
	SDL_INIT_NOPARACHUTE					= 0,							//0,							// 0000 0000 
	SDL_INIT_TIMER							= 1 << 0,						//1,							// 0000 0001
	SDL_INIT_AUDIO							= 1 << 1,						//2,							// 0000 0010
	SDL_INIT_VIDEO							= 1 << 2,						//4,							// 0000 0100
	SDL_INIT_JOYSTICK						= 1 << 3,						//8,							// 0000 1000
	SDL_INIT_HAPTIC							= 1 << 4,						//16,							// 0001 0000
	SDL_INIT_GAMECONTROLLER					= 1 << 5,						//32,							// 0010 0000
	SDL_INIT_EVENTS							= 1 << 6,						//64,							// 0100 0000		
	SDL_INIT_EVERYTHING						= 127							//127						// 0111 1111
} INIT_VALUES;

void InitializeGraphics(INIT_VALUES);
