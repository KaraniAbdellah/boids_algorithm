#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "boids/header.h"

int main() {
    SDL_Window* win = NULL;
    SDL_Renderer* ren = NULL;
    ball* ball_rect = malloc(sizeof(ball));
    int index_rects = 0;
    SDL_Rect* rects = malloc(sizeof(SDL_Rect) * 100); // we can draw 100 rectangles

    if (!initialize_window(&win, &ren)) {
        printf("Failed to initialize window and renderer\n");
        return -1;
    }

    setup(ball_rect, WIDTH / 2, HEIGHT / 2);

    int game_is_running = 1;
    while (game_is_running) {
        handle_events(&game_is_running, &ren, ball_rect, rects, &index_rects);
        update_game_state(rects, &index_rects);
        render_game(&ren, ball_rect, rects, &index_rects);
    }

    destroy_window(&win, &ren);
    free(ball_rect);
    free(rects);

    return 0;
}

