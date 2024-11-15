#ifndef BOIDS 
#define BOIDS

#include <SDL2/SDL.h>

	#define WIDTH 300
	#define HEIGHT 300
	#define FALSE 0
	#define TRUE 1
	#define WINDOW_WIDTH 800
	#define WINDOW_HEIGHT 600

	
	typedef struct ball {
		float x;
		float y;
		float width; 
		float height;
	} ball;
	
	// start declaration of functions prototypes
	int initialize_window(SDL_Window** win, SDL_Renderer** ren);
	void destroy_window(SDL_Window** win, SDL_Renderer** ren);
	void process_input(int *game_is_running);
	void update(ball *ball_rect);
	void render(SDL_Renderer** ren, ball *ball_rect);
	void setup(ball *ball_rect);








#endif
