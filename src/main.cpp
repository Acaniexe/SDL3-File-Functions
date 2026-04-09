#include "game.h"

int main(int argc, char* argv[]) {
    Game game;

    if (!init(game)) return 1;

    Uint64 perfFrequency = SDL_GetPerformanceFrequency();
    Uint64 lastCounter = SDL_GetPerformanceCounter();

    while (game.running) {
        Uint64 currentCounter = SDL_GetPerformanceCounter();
        double deltaTime = (double)(currentCounter - lastCounter) / (double)(perfFrequency);
        lastCounter = currentCounter;

        eventHandler(game);
        update(game, deltaTime);
        render(game);
    }

    cleanUp(game);
    return 0;
}