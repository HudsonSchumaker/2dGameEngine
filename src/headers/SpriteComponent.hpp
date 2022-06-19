//
// SchumakerLab
// Dodoi Engine
// Hudson Schumaker
//

#pragma once
#include "Basic.hpp"
#include "Component.hpp"
#include "Vec2.hpp"

namespace dodoi {
    class SpriteComponent : public Component {
        public:
            std::string spriteName;
            Vec2 position;
            Vec2 size;
            short zOrder;
    };
}
