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

        // Components
        template <typename T, typename ...TArgs> void AddComponent(Entity e, TArgs&& ...args);
        template <typename T> void RemoveComponent(Entity e);
        template <typename T> bool HasComponent(Entity e) const;

        // Systems
        template <typename T, typename ...TArgs> void AddSystem(BasicSystem s, TArgs&& ...args);
        template <typename T> void RemoveSystem();
        template <typename T> bool HasSystem() const;
        template <typename T> T& GetSystem() const;
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

template <typename T> bool Registry::HasComponent(Entity e) const {
    const auto componentId = Component<T>::GetId();
    const auto entityId = e.GetId();

    return entityComponentSignatures[entityId].test(componentId);
}

template <typename T, typename ...TArgs> void Registry::AddSystem(BasicSystem s, TArgs &&...args) {
    T* newSystem(new T(std::forward<TArgs>(args)...));
    systems.insert(std::make_pair(std::type_index(typeid(T)), newSystem));
}

template <typename T> void Registry::RemoveSystem() {
    auto system = systems.find(std::type_index(typeid(T)));
    systems.erase(system);
}

template <typename T> bool Registry::HasSystem() const {
    return systems.find(std::type_index(typeid(T))) != systems.end();
}

template <typename T> T& Registry::GetSystem() const {
    auto system = systems.find(std::type_index(typeid(T)));
    return *(std::static_pointer_cast<T>()(system->second));
}