//
// SchumakerLab
// Dodoi Engine
// Hudson Schumaker
//

#pragma once
#include "Basic.hpp"
#include "Entity.hpp"

namespace dodoi {
    class BasicSystem {
        private:
            std::vector<Entity> entities;

        protected:

        public:   
            virtual void update() = 0; 
            virtual void update(float deltaTime) = 0;
            virtual void update(SDL_Renderer* renderer) = 0;

    };
}