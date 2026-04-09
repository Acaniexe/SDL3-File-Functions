#include "player.h"
#include <cmath>

void updatePlayer(Player& player, const InputState& input, int windowWidth, int windowHeight, double deltaTime) {
    float dx = 0.0f;
    float dy = 0.0f;

    if (input.moveUp)    dy -= 1.0f;
    if (input.moveDown)  dy += 1.0f;
    if (input.moveLeft)  dx -= 1.0f;
    if (input.moveRight) dx += 1.0f;

    // Normalize diagonal movement
    if (dx != 0.0f || dy != 0.0f) {
        float length = sqrtf(dx * dx + dy * dy);
        dx /= length;
        dy /= length;
    }

    player.player.x += dx * player.moveSpeed * deltaTime;
    player.player.y += dy * player.moveSpeed * deltaTime;

    if (player.player.x < 0) player.player.x = 0;
    if (player.player.y < 0) player.player.y = 0;
    if (player.player.x + player.player.w > windowWidth) player.player.x = windowWidth - player.player.w;
    if (player.player.y + player.player.h > windowHeight) player.player.y = windowHeight - player.player.h;
}

void renderPlayer(SDL_Renderer* renderer, const Player& player) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
    SDL_RenderFillRect(renderer, &player.player);
}