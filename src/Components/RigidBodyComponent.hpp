#ifndef RigidBodyComponent_hpp
#define RigidBodyComponent_hpp

#include <glm/glm.hpp>

struct RigidBodyComponent {
    glm::vec2 velocity;

    RigidBodyComponent(glm::vec2 velocity = glm::vec2(0.0, 0.0)) {
        this->velocity = velocity;
    }
};

#endif /* RigidBodyComponent_hpp */