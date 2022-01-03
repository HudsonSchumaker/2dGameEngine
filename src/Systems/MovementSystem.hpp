#ifndef MovementSystem_hpp
#define MovementSystem_hpp

#include "../ECS/BasicSystem.hpp"

class MovementSystem final : public BasicSystem {
    private:
        

    public:
        MovementSystem();
        ~MovementSystem();
        void Update();
};

#endif /* MovementSystem_hpp */