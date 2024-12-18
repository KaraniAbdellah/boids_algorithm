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



void process_input(int *game_is_running, SDL_Renderer** ren, ball *ball_rect, SDL_Rect* rects, int* index_rects) {
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch(event.type) {
		case SDL_QUIT: // stop looping 
			*game_is_running = FALSE;
			break;
		case SDL_KEYDOWN:
				*game_is_running = FALSE;
			break;
		case SDL_MOUSEBUTTONDOWN:
			setup(ball_rect, event.button.x, event.button.y);
			*index_rects = *index_rects + 1;
			render(ren, ball_rect, rects, index_rects);
		default: break;
	}
}



void update(SDL_Rect *rects, int *index_rects) {
    SDL_Delay(50);

  	for (int i = 0; i <= *index_rects; i++) {
  		rects[i].x = rects[i].x + 1;
  		rects[i].y = rects[i].y + 1;
  	}
}



SDL_Rect create_rect(ball *ball_rect, SDL_Renderer **ren) {
	SDL_Rect ball_rect_ren = {
		ball_rect->x,
		ball_rect->y,
		ball_rect->width,
		ball_rect->height
	};
	SDL_SetRenderDrawColor(*ren, 255, 255, 255, 255);
	
	return ball_rect_ren;
}

void render(SDL_Renderer** ren, ball *ball_rect, SDL_Rect* rects, int* index_rects) {
	SDL_SetRenderDrawColor(*ren, 0, 0, 0, 255);
	SDL_RenderClear(*ren);
	
	// Draw a rectangle
	rects[*index_rects] = create_rect(ball_rect, ren);
	
	// Present all Rectangle
	for (int i = 0; i <= *index_rects; i++) {
		SDL_RenderFillRect(*ren, &rects[i]);
	}
	
	SDL_RenderPresent(*ren);
}



void setup(ball *ball_rect, int x, int y) {
	ball_rect->x = x;
	ball_rect->y = y;
	ball_rect->width = 5;
	ball_rect->height = 5;
}



void destroy_window(SDL_Window** win, SDL_Renderer **ren) {
	SDL_DestroyRenderer(*ren);
	SDL_DestroyWindow(*win);
	SDL_Quit();
} 


















