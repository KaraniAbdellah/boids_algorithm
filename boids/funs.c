#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "header.h"

// Initialize SDL & Create window
int initialize_window(SDL_Window** win, SDL_Renderer** ren) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL\n");
        return 0;
    }

    *win = SDL_CreateWindow("BOIDS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);
    if (!*win) return 0;

    *ren = SDL_CreateRenderer(*win, -1, SDL_RENDERER_ACCELERATED);
    if (!*ren) return 0;

    return 1;
}

// Handle events
void handle_events(int* game_is_running, SDL_Renderer** ren, ball* ball_rect, SDL_Rect* rects, int* index_rects) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *game_is_running = 0;
                break;
            case SDL_KEYDOWN:
                *game_is_running = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                setup(ball_rect, event.button.x, event.button.y);
                *index_rects += 1;
                render_game(ren, ball_rect, rects, index_rects);
                break;
        }
    }
}

// Update game state
void update_game_state(SDL_Rect* rects, int* index_rects) {
    for (int i = 0; i <= *index_rects; i++) {
        rects[i].x += 1;
        rects[i].y += 1;
    }
}

// Create rectangle for ball
SDL_Rect create_rect(ball* ball_rect, SDL_Renderer** ren) {
    SDL_Rect rect = { ball_rect->x, ball_rect->y, ball_rect->width, ball_rect->height };
    SDL_SetRenderDrawColor(*ren, 255, 255, 255, 255);
    return rect;
}

// Render game objects
void render_game(SDL_Renderer** ren, ball* ball_rect, SDL_Rect* rects, int* index_rects) {
    SDL_SetRenderDrawColor(*ren, 0, 0, 0, 255);
    SDL_RenderClear(*ren);

    // Draw rectangles
    rects[*index_rects] = create_rect(ball_rect, ren);
    for (int i = 0; i <= *index_rects; i++) {
        SDL_RenderFillRect(*ren, &rects[i]);
    }

    SDL_RenderPresent(*ren);
}

// Setup ball position
void setup(ball* ball_rect, int x, int y) {
    ball_rect->x = x;
    ball_rect->y = y;
    ball_rect->width = 5;
    ball_rect->height = 5;
}

// Destroy window and renderer
void destroy_window(SDL_Window** win, SDL_Renderer** ren) {
    SDL_DestroyRenderer(*ren);
    SDL_DestroyWindow(*win);
    SDL_Quit();
}

