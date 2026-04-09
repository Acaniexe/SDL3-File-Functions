#pragma once
#include <SDL3/SDL.h>
#include "input.h"

struct Player {
    SDL_FRect player = {10.0f, 10.0f, 30.0f, 30.0f};
    float moveSpeed = 300.0f;
};

void updatePlayer(Player& player, const InputState& input, int windowWidth, int windowHeight, double deltaTime);
void renderPlayer(SDL_Renderer* renderer, const Player& player);