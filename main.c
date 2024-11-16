#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "boids/header.h"
#include <unistd.h>
#include <SDL2/SDL_timer.h>



int main() {
	
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;
	ball *ball_rect = (ball *) malloc(sizeof(ball));
	
	int game_is_running = initialize_window(&win, &ren);
	setup(ball_rect);
	while (game_is_running) {
		process_input(&game_is_running);
		update(ball_rect);
		render(&ren, ball_rect);
	}

    destroy_window(&win, &ren);

    return 0;
}
























/* SETPS
	Initialize SDL.
	Create a window.
	Create a renderer for the window.
	Set the drawing color.
	Clear the window.
	Display the rendered content.
	Wait for a specified time.
	Destroy the renderer and window.
	Quit SDL.
*/











