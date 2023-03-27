/*
    SchumakerTeam
    Hudson Schumaker
*/

#include "include/Main.h"
#include "gfx/Gfx.h"
#include "gfx/AssetManager.h"
#include "sfx/AudioManager.h"
#include "io/FileUtils.h"

int main(int argc, char* argv[]) {
    setUp();
    load();

    for (;;);
    return 0;
}

void setUp() {
    Gfx::getInstance()->setGfxContext();
}

void load() {
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