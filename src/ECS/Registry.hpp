#pragma once
#include <set>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include "BasicSystem.hpp"
#include "Component.hpp"
#include "Pool.hpp"

class Registry final {
    private:
        int numEntities = 0;
        std::vector<IPool*> componentPools;
        std::vector<Signature> entityComponentSignatures;
        std::unordered_map<std::type_index, BasicSystem*> systems;
        std::set<Entity> entitiesToBeAdded;
        std::set<Entity> entitiesToBeDestroyed;

    public:
        Registry() = default;
        ~Registry();

        void Update();
        Entity CreateEntity();
        void AddEntityToSystem(Entity e);

};