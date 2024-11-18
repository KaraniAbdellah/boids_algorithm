#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "boids/header.h"
#include <unistd.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_events.h>



int main() {
	
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;
	ball *ball_rect = (ball *) malloc(sizeof(ball));
	int index_rects = 0;
	SDL_Rect *rects = malloc(sizeof (SDL_Rect) * 100); // we can draw 100 rectangle
	
	int game_is_running = initialize_window(&win, &ren);
	setup(ball_rect, WIDTH / 2, HEIGHT / 2);
	while (game_is_running) {
		process_input(&game_is_running, &ren, ball_rect, rects, &index_rects);
		update(rects, &index_rects);
		render(&ren, ball_rect, rects, &index_rects);
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











