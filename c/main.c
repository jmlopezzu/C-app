#include <SDL.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "My SDL App",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event e;
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Rendering logic
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Set color to white
        SDL_RenderClear(renderer);  // Clear the renderer with the set color

        // Draw a red rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Set color to red
        SDL_Rect rect = {100, 100, 50, 50};  // Rectangle position (x, y) and size (width, height)
        SDL_RenderFillRect(renderer, &rect);  // Fill the rectangle

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
