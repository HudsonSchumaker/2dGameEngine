#include <iostream>
#include "Game.hpp"

Game::Game() {
    isRunning = false;

}

Game::~Game() {

}

void Game::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error on initializing SDL2." << std::endl;
        return;
    }
    
    window = SDL_CreateWindow(
        "Game", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        800,
        600,
        SDL_WINDOW_METAL
    );
    if (!window) {
        std::cerr << "Error creating SDL2 window." << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL2 renderer." << std::endl;
        return;
    }
    isRunning = true;
}

void Game::Run() {
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
    //TODO
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 50);
    SDL_RenderClear(renderer);
    
    //TODO

    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}