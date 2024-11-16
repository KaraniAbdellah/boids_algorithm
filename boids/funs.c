#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>



/*
	each boid has [position, velocity, acceleration]
	roles of boids: [seperation, alignment, cohesion]

	Separation: boids move away from other boids that are too close
	Alignment: boids attempt to match the velocities of their neighbors
	Cohesion: boids move toward the center of mass of their neighbors

*/





// initialize SDL & Create window
int initialize_window(SDL_Window** win, SDL_Renderer** ren) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Erorr Initialize Widnow");
		return FALSE;		
	}
	
	*win = SDL_CreateWindow(
		"BOIDS",
		SDL_WINDOWPOS_CENTERED, // x position
		SDL_WINDOWPOS_CENTERED, // y position
		WINDOW_WIDTH, // width
		WINDOW_HEIGHT, // height
		SDL_WINDOW_BORDERLESS
	);
	if (*win == NULL) return FALSE;
	
	*ren = SDL_CreateRenderer(*win, -1, 0);
	if (*ren == NULL) return FALSE;
	
	return TRUE;
}


void process_input(int *game_is_running) {
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch(event.type) {
		case SDL_QUIT: // stop looping 
			game_is_running = FALSE;
			break;
		case SDL_KEYDOWN:
				game_is_running = FALSE;
			break;
		default: break;
	}
}


void update(ball *ball_rect) {
    SDL_Delay(50);

    ball_rect->x += 1;
    ball_rect->y += 1;

   
}


void render(SDL_Renderer** ren, ball *ball_rect) {
	SDL_SetRenderDrawColor(*ren, 0, 0, 0, 255);
	SDL_RenderClear(*ren);
	
	// Draw a rectangle
	SDL_Rect ball_rect_ren = {
		ball_rect->x,
		ball_rect->y,
		ball_rect->width,
		ball_rect->height
	};
	SDL_SetRenderDrawColor(*ren, 255, 255, 255, 255);
	SDL_RenderFillRect(*ren, &ball_rect_ren);
	
	// Here we can start drawing objects
	SDL_RenderPresent(*ren);
	
}


void setup(ball *ball_rect) {
	ball_rect->x = WIDTH / 2;
	ball_rect->y = HEIGHT / 2;
	ball_rect->width = 5;
	ball_rect->height = 5;
}


void destroy_window(SDL_Window** win, SDL_Renderer **ren) {
	SDL_DestroyRenderer(*ren);
	SDL_DestroyWindow(*win);
	SDL_Quit();
} 


















