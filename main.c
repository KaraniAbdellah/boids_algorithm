#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "boids/header.h"
// for initializing and shutdown functions
#include <SDL2/SDL.h>
// for rendering images and graphics on screen
// #include <SDL2/SDL_image.h>
// for using SDL_Delay() functions
// #include <SDL2/SDL_timer.h>



int main() {
	
	// returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);
    
	
	
	
	return 0;
}









