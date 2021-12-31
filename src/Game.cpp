#include <iostream>
#include "Game.hpp"
#include "Logger.hpp"

SDL_Surface* tankSurface;
SDL_Texture* tankSprite;

Game::Game() {
    Logger::Engine("Game started.");
    isRunning = false;
}

Game::~Game() {
    Logger::Engine("Game ended.");
}

void Game::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        //std::cerr << "Error on initializing SDL2." << std::endl;
        Logger::Error("Error on initializing SDL2.");
        return;
    }

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    width = 640; //displayMode.w;
    height = 480;//displayMode.h;

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
        //std::cerr << "Error creating SDL2 window." << std::endl;
        Logger::Error("Error creating SDL2 window.");
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        //std::cerr << "Error creating SDL2 renderer." << std::endl;
        Logger::Error("Error creating SDL2 renderer.");
        return;
    }
    SDL_SetWindowOpacity(window, 0.5f);
   // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    isRunning = true;
}

void Game::Setup() {
    pos = glm::vec2(10.0, 10.0);
    vel = glm::vec2(10.0, 0.0);

    tankSurface = IMG_Load("./assets/images/tank-tiger-right.png");
    tankSprite = SDL_CreateTextureFromSurface(renderer, tankSurface);
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
    int timeToWait = 
    MILLISECS_PER_FRAME - (SDL_GetTicks() - previousFrame);

    if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME) {
        SDL_Delay(timeToWait);
    }

    double deltaTime = (SDL_GetTicks() - previousFrame) / 1000.0;
    previousFrame = SDL_GetTicks();
   
    pos.x += vel.x * deltaTime;
    pos.y += vel.y * deltaTime;    
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 255, 155, 255);
    SDL_RenderClear(renderer);

    SDL_Rect rect = { 
        static_cast<int>(pos.x), 
        static_cast<int>(pos.y),
        32,
        32 
    };

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, tankSprite, NULL, &rect, 0.0, NULL, flip);
    //SDL_RenderCopy(renderer, tankSprite, NULL, &rect);
    
    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}