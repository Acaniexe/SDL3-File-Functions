#include "game.h"
#include <iostream>

void eventHandler(Game& game) {
    SDL_Event event;
    game.input.leftDown = false;
    game.input.leftReleased = false;
    game.input.rightDown = false;
    game.input.rightReleased = false;
    game.input.spacePressed = false;
    game.input.spaceReleased = false;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                game.running = false;
                break;

            case SDL_EVENT_MOUSE_MOTION:
                game.input.mouseX = event.motion.x;
                game.input.mouseY = event.motion.y;
                break;

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    game.input.leftDown = true;
                    game.input.leftHeld = true;
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    game.input.rightDown = true;
                    game.input.rightHeld = true;
                }
                break;

            case SDL_EVENT_MOUSE_BUTTON_UP:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    game.input.leftReleased = true;
                    game.input.leftHeld = false;
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    game.input.rightReleased = true;
                    game.input.rightHeld = false;
                }
                break;

            case SDL_EVENT_KEY_DOWN:
                if (event.key.repeat == 0) {
                    if (event.key.scancode == SDL_SCANCODE_SPACE) {
                        game.input.spacePressed = true;
                        game.input.spaceHeld = true;
                    } else if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
                        game.running = false;
                    }
                }
                break;

            case SDL_EVENT_KEY_UP:
                if (event.key.repeat == 0) {
                    if (event.key.scancode == SDL_SCANCODE_SPACE) {
                        game.input.spaceReleased = true;
                        game.input.spaceHeld = false;
                    }
                }
                break;

            case SDL_EVENT_WINDOW_RESIZED:
                game.windowWidth = event.window.data1;
                game.windowHeight = event.window.data2;
                std::cout << "Window width: " << game.windowWidth << std::endl;
                std::cout << "Window height: " << game.windowHeight << std::endl;
                break;
        }
    }

    const bool* keystate = SDL_GetKeyboardState(NULL);
    game.input.moveUp = keystate[SDL_SCANCODE_W];
    game.input.moveDown = keystate[SDL_SCANCODE_S];
    game.input.moveRight = keystate[SDL_SCANCODE_D];
    game.input.moveLeft = keystate[SDL_SCANCODE_A];
}