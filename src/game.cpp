#include "game.h"
#include "renderer.h"
#include <iostream>
#include <cmath>

bool init(Game& game) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL failed: " << SDL_GetError() << std::endl;
        return false;
    }

    game.window = SDL_CreateWindow("Testing", 900, 900, SDL_WINDOW_RESIZABLE);
    if (!game.window) {
        std::cout << "Window failed: " << SDL_GetError() << std::endl;
        return false;
    }

    game.renderer = SDL_CreateRenderer(game.window, NULL);
    if (!game.renderer) {
        std::cout << "Renderer failed: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void update(Game& game, double deltaTime) {
    updatePlayer(game.player, game.input, game.windowWidth, game.windowHeight, deltaTime);
}

void render(Game& game) {
    beginFrame(game.renderer);
    renderPlayer(game.renderer, game.player);
    endFrame(game.renderer);
}

void cleanUp(Game& game) {
    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyWindow(game.window);
    SDL_Quit();
}
