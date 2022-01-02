#pragma once
#include <set>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include "BasicSystem.hpp"
#include "Component.hpp"
#include "Pool.hpp"

class Registry {
    private:
        int numEntities = 0;
        std::vector<IPool*> componentPools;
        std::vector<Signature> entityComponentSignatures;
        std::unordered_map<std::type_index, BasicSystem*> systems;
        std::set<Entity> entitiesToBeAdded;
        std::set<Entity> entitiesToBeDestroyed;

    public:
        Registry() = default;
        ~Registry() = default;

        void Update();
        Entity CreateEntity();
        template <typename T, typename ...TArgs> void AddComponent(Entity e, TArgs&& ...args);
        template <typename T> void RemoveComponent(Entity e);
        template <typename T> bool HasComponent(Entity e);
};

template <typename T, typename ...TArgs> void Registry::AddComponent(Entity e, TArgs&& ...args) {
    const auto componentId = Component<T>::GetId();
    const auto entityId = e.GetId();

    if (componentId >= componentPools.size()) {
        componentPools.resize(componentId + 1, nullptr);
    }

    if (!componentPools[componentId]) {
        Pool<T>* newComponentPool = new Pool<T>();
        componentPools[componentId] = newComponentPool;
    }

    Pool<T>* componentPool = componentPools[componentId];
    if (entityId >= componentPool->GetSize()) {
        componentPool->Resize(numEntities);
    }

    T newComponent(std::forward<TArgs>(args)...);
    componentPool->Set(entityId, newComponent);
    entityComponentSignatures[entityId].set(componentId);
}

template <typename T> void Registry::RemoveComponent(Entity e) {
    const auto componentId = Component<T>::GetId();
    const auto entityId = e.GetId();

    entityComponentSignatures[entityId].set(componentId, false);
}

template <typename T> bool Registry::HasComponent(Entity e) {
    const auto componentId = Component<T>::GetId();
    const auto entityId = e.GetId();

    return entityComponentSignatures[entityId].test(componentId);
}