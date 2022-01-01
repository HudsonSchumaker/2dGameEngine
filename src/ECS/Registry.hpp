#pragma once
#include <vector>
#include "Pool.hpp"

class Registry final {
    private:
        int numEntities = 0;
        std::vector<IPool*> data;

    public:
        Registry() = default;
        ~Registry();
};