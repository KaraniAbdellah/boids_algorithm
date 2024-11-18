#ifndef BOIDS_H
#define BOIDS_H

#include <SDL2/SDL.h>

#define WIDTH 300
#define HEIGHT 300
#define FALSE 0
#define TRUE 1
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
// Use this in classic method [Now we have SDL_Delay()]
#define FPS 30 // frames per second
#define FRAME_TARGET_TIME (1000 / FPS) // Each millisecond pass 30 frames

typedef struct ball {
    float x;
    float y;
    float width; 
    float height;
} ball;

// Function prototypes
int initialize_window(SDL_Window** win, SDL_Renderer** ren);
void destroy_window(SDL_Window** win, SDL_Renderer** ren);
void process_input(int *game_is_running, SDL_Renderer** ren, ball *ball_rect, SDL_Rect* rects, int* index_rects);
void update(SDL_Rect *rects, int *index_rects);
void render(SDL_Renderer** ren, ball *ball_rect, SDL_Rect* rects, int* index_rects);
void setup(ball *ball_rect, int x, int y);
SDL_Rect create_rect(ball *ball_rect, SDL_Renderer **ren);

#endif // BOIDS_H

