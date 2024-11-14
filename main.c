#include <SDL2/SDL.h>

int main() {
    // Initialize the SDL library for video
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1; // Exit if initialization fails
    }

    // Create a fullscreen window
    SDL_Window *window = SDL_CreateWindow(
        "BOIDS_ALGO",                   // Window title
        SDL_WINDOWPOS_CENTERED,         // X position (centered)
        SDL_WINDOWPOS_CENTERED,         // Y position (centered)
        0,                              // Width (0 to auto-adjust with fullscreen)
        0,                              // Height (0 to auto-adjust with fullscreen)
        SDL_WINDOW_FULLSCREEN_DESKTOP   // Fullscreen mode on desktop resolution
    );

    // Check if window creation failed
    if (!window) {
        SDL_Quit();
        return 1; // Exit if window creation fails
    }

    // Keep the window open for 3 seconds
    SDL_Delay(3000);

    // Clean up resources
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

