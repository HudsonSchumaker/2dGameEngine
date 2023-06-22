/*
    SchumakerTeam
    Hudson Schumaker
*/

#include "include/Main.h"
#include "gfx/Gfx.h"
#include "gfx/AssetManager.h"
#include "sfx/AudioManager.h"
#include "io/FileUtils.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "ecs/EntityManager.h"

int main(int argc, char* argv[]) {
    setUp();
    auto renderer = Gfx::getInstance()->getRenderer();

    SplashScreen* splashScreen = new SplashScreen();
    splashScreen->run();
    delete splashScreen;

    Menu* menu = new Menu();
    menu->run();
    delete menu;

    SDL_Rect rect = { 100, 100, 64, 64 };
    int x, y;
    auto controller = SDL_GameControllerOpen(0);

    bool exit = false;
    while (!exit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        printf("Left mouse button down at (%d, %d)\n", event.button.x, event.button.y);
                    } else if (event.button.button == SDL_BUTTON_RIGHT) {
                        printf("Right mouse button down at (%d, %d)\n", event.button.x, event.button.y);
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        printf("Left mouse button up at (%d, %d)\n", event.button.x, event.button.y);
                    } else if (event.button.button == SDL_BUTTON_RIGHT) {
                        printf("Right mouse button up at (%d, %d)\n", event.button.x, event.button.y);
                    }
                    break;
                case SDL_MOUSEWHEEL:
                    if (event.wheel.y > 0) {
                        printf("Mouse wheel scrolled up (%d)\n", event.wheel.y);
                    } else if (event.wheel.y < 0) {
                        printf("Mouse wheel scrolled down (%d)\n", event.wheel.y);
                    }
                    break;
                case SDL_MOUSEMOTION:
                    x = event.motion.x; y = event.motion.y;
                    printf("Mouse moved to (%d, %d)\n", event.motion.x, event.motion.y);
                    break;
            }

            Sint16 axisX = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);
            Sint16 axisY = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);

            x += axisX / 3276; // Scale the value to move the player sprite
            y += axisY / 3276;

        }

        // Render something to show that the program is running
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        rect.x = x - (rect.w / 2);
        rect.y = y - (rect.h / 2);

        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }

    quit();

    return 0;
}

void setUp() {
    Gfx::getInstance()->setGfxContext();
    AssetManager::getInstance()->load();
    AudioManager::getInstance()->load();
}

void quit() {
    SDL_GameControllerClose(0);
    IMG_Quit();
    TTF_Quit();
    Mix_HaltChannel(-1);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}
