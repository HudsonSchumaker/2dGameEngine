//
// SchumakerLab
// Dodoi Engine
// Hudson Schumaker
//

#pragma once
#include "Basic.hpp"
#include "Component.hpp"

namespace dodoi {
    class Entity {
        private:
            std::vector<Component> components;

        public:
            Entity() = default;
            short id;
            void add(Component component);
    };
}