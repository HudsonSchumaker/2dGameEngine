#pragma once
#include <vector>
#include "Pool.hpp"

class Registry final {
    private:
        int numEntities = 0;
        std::vector<IPool*> componentPools;

    public:
        Registry() = default;
        ~Registry();
};