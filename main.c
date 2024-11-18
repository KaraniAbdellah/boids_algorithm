#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>

#define NUM_BOIDS 100
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_SPEED 3
#define MAX_FORCE 0.05f

typedef struct {
    float x, y;
    float vx, vy;
    float ax, ay;
} Boid;

SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;
Boid boids[NUM_BOIDS];

int initialize_window(SDL_Window** win, SDL_Renderer** ren) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL\n");
        return 0;
    }
    *win = SDL_CreateWindow("Boids Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);
    if (*win == NULL) return 0;
    *ren = SDL_CreateRenderer(*win, -1, 0);
    if (*ren == NULL) return 0;
    return 1;
}

void setup_boids() {
    for (int i = 0; i < NUM_BOIDS; i++) {
        boids[i].x = rand() % WINDOW_WIDTH;
        boids[i].y = rand() % WINDOW_HEIGHT;
        boids[i].vx = ((rand() % 200) / 100.0f) - 1.0f;
        boids[i].vy = ((rand() % 200) / 100.0f) - 1.0f;
        boids[i].ax = 0;
        boids[i].ay = 0;
    }
}

void apply_force(Boid *boid, float fx, float fy) {
    boid->ax += fx;
    boid->ay += fy;
}

void update_boids() {
    for (int i = 0; i < NUM_BOIDS; i++) {
        boids[i].vx += boids[i].ax;
        boids[i].vy += boids[i].ay;

        // Limit speed
        if (sqrt(boids[i].vx * boids[i].vx + boids[i].vy * boids[i].vy) > MAX_SPEED) {
            float angle = atan2(boids[i].vy, boids[i].vx);
            boids[i].vx = MAX_SPEED * cos(angle);
            boids[i].vy = MAX_SPEED * sin(angle);
        }

        boids[i].x += boids[i].vx;
        boids[i].y += boids[i].vy;

        // Wrap around the screen
        if (boids[i].x < 0) boids[i].x = WINDOW_WIDTH;
        if (boids[i].x > WINDOW_WIDTH) boids[i].x = 0;
        if (boids[i].y < 0) boids[i].y = WINDOW_HEIGHT;
        if (boids[i].y > WINDOW_HEIGHT) boids[i].y = 0;

        boids[i].ax = 0;
        boids[i].ay = 0;
    }
}

void render_boids(SDL_Renderer *ren) {
    for (int i = 0; i < NUM_BOIDS; i++) {
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderDrawPoint(ren, (int)boids[i].x, (int)boids[i].y);
    }
}

void process_input(int *game_is_running, SDL_Renderer **ren, SDL_Rect *rects, int *index_rects) {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            *game_is_running = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            rects[*index_rects].x = event.button.x;
            rects[*index_rects].y = event.button.y;
            rects[*index_rects].w = 10;
            rects[*index_rects].h = 10;
            (*index_rects)++;
            break;
    }
}

void render(SDL_Renderer *ren, SDL_Rect *rects, int *index_rects) {
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);

    // Draw rectangles created by mouse clicks
    for (int i = 0; i < *index_rects; i++) {
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255); // Red color for rectangles
        SDL_RenderFillRect(ren, &rects[i]);
    }

    render_boids(ren);

    SDL_RenderPresent(ren);
}

void destroy_window(SDL_Window **win, SDL_Renderer **ren) {
    SDL_DestroyRenderer(*ren);
    SDL_DestroyWindow(*win);
    SDL_Quit();
}

int main() {
    SDL_Window* win = NULL;
    SDL_Renderer* ren = NULL;
    int game_is_running = initialize_window(&win, &ren);
    SDL_Rect *rects = malloc(sizeof(SDL_Rect) * 100); // max 100 rectangles
    int index_rects = 0;

    setup_boids();

    while (game_is_running) {
        process_input(&game_is_running, &ren, rects, &index_rects);
        update_boids();
        render(ren, rects, &index_rects);
    }

    destroy_window(&win, &ren);
    free(rects);
    return 0;
}

