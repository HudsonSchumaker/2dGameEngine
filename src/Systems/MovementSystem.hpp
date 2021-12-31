#pragma once
#include "../ECS/BasicSystem.hpp"

class MovementSystem final : public BasicSystem {
    private:
        

    public:
        MovementSystem();
        ~MovementSystem();
        void Update();
};