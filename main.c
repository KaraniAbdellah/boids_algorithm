#include <SDL2/SDL.h>
#include <stdio.h>
#include "boids/header.h"



int main() {
	
	// Initialize SDL for video
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }
    
    // Create a window
    SDL_Window *window = SDL_CreateWindow(
        "BOIDS_ALGO",            // Window title
        SDL_WINDOWPOS_CENTERED,     // X position (centered)
        SDL_WINDOWPOS_CENTERED,     // Y position (centered)
        800,                        // Width
        600,                        // Height
        0                           // Window flags (no special options)
    );
    
    // Check if the window was created successfully
    if (!window) {
        SDL_Quit();
        return 1;
    }

	// Create a renderer (used for drawing inside the window)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Display the changes made to the window
    SDL_RenderPresent(renderer);

	// Wait for 3 seconds
    SDL_Delay(10000);
    
    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    

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











