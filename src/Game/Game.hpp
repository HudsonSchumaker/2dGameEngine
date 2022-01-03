#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <glm/glm.hpp>
#include "../ECS/Registry.hpp"

const int FPS = 144;
const int MILLI_SECS_PER_FRAME = 1000 / FPS;

class Game final {
    private:
        bool isRunning;
        int previousFrame = 0;
        SDL_Window* window;     // C lib
        SDL_Renderer* renderer; // C lib
        std::unique_ptr<Registry> registry;

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

#endif /* Game_hpp */