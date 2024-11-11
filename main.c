#include <stdio.h>
#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include <math.h>
#include <string.h>
#include "boids/header.h"
#include <SDL2/SDL.h>



int main() {
	
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if (!window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Delay(2000); // Show window for 2 seconds
    SDL_DestroyWindow(window);
    SDL_Quit();
	
	
	
	return 0;
}


// mlx_string_put(mlx, new_win, (WIDTH / 2) - 50, 100, 0x0000FF00, "HELLO WORLD");








