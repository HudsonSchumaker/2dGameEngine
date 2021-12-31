#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <glm/glm.hpp>

const int FPS = 144;
const int MILLISECS_PER_FRAME = 1000 / FPS;

class Game final {
    private:
        int previousFrame = 0;
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        glm::vec2 pos;
        glm::vec2 vel;

    public:
        Game();
        ~Game();
        void Initialize();
        void Setup();
        void Run();
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();

        int width;
        int height;
};