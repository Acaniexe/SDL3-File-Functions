#pragma once
#include <SDL3/SDL.h>
#include "input.h"
#include "player.h"

struct Game {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int windowWidth = 900;
    int windowHeight = 900;
    bool running = true;

    InputState input;
    Player player;
};

bool init(Game& game);
void eventHandler(Game& game);
void update(Game& game, double deltaTime);
void render(Game& game);
void cleanUp(Game& game);