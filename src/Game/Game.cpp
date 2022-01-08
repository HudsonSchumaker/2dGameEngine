#include <iostream>
#include "Game.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/RigidBodyComponent.hpp"
#include "../Log/Logger.hpp"
#include "../ECS/RegistryEntity.hpp"

Game::Game() {
    Logger::Engine("Game started.");
    isRunning = false;
   // registry = std::make_unique<Registry>();
}

Game::~Game() {
    Logger::Engine("Game ended.");
}

void Game::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::Error("Error on initializing SDL2.");
        return;
    }

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    width = 640;  //displayMode.w;
    height = 480; //displayMode.h;

    window = SDL_CreateWindow(
        "Game", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        width,
        height,
        //SDL_WINDOW_BORDERLESS |
        SDL_WINDOW_METAL
    );
    if (!window) {
        Logger::Error("Error creating SDL2 window.");
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        Logger::Error("Error creating SDL2 renderer.");
        return;
    }
    // SDL_SetWindowOpacity(window, 0.5f);
    // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    isRunning = true;
}

void Game::Setup() {
    Entity tank = Registry::getInstance().CreateEntity();
   // registry->AddComponent<TransformComponent>(tank, glm::vec2(10.0, 10.0), glm::vec2(1.0, 1.0), 0.0);
   // registry->AddComponent<RigidBodyComponent>(tank, glm::vec2(5.0, 0.0));
   tank.AddComponent<TransformComponent>(tank, glm::vec2(10.0, 10.0), glm::vec2(1.0, 1.0), 0.0);

}

void Game::Run() {
    Setup();
    while(isRunning) {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::ProcessInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    isRunning = false;
                }
                break;
        }
    }
}

void Game::Update() {
    int timeToWait = MILLI_SECS_PER_FRAME - (SDL_GetTicks() - previousFrame);

    if (timeToWait > 0 && timeToWait <= MILLI_SECS_PER_FRAME) {
        SDL_Delay(timeToWait);
    }

    double deltaTime = (SDL_GetTicks() - previousFrame) / 1000.0;
    previousFrame = SDL_GetTicks();
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 255, 155, 255);
    SDL_RenderClear(renderer);

    //SDL_Rect rect = {
      //  static_cast<int>(pos.x),
      //  static_cast<int>(pos.y),
      //  32,
      //  32
    //};

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    // SDL_RenderCopyEx(renderer, tankSprite, NULL, &rect, 0.0, NULL, flip);
    // SDL_RenderCopy(renderer, tankSprite, NULL, &rect);
    
    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}