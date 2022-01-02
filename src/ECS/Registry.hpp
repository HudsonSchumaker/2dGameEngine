#pragma once
#include <set>
#include <vector>
#include <typeindex>
#include <unordered_map>
#include "BasicSystem.hpp"
#include "Component.hpp"
#include "Pool.hpp"

class Registry {
    private:
        int numEntities = 0;
        // std::vector<IPool*> componentPools;
        std::vector<std::shared_ptr<IPool>> componentPools;
        std::vector<Signature> entityComponentSignatures;
        // std::unordered_map<std::type_index, BasicSystem*> systems;
        std::unordered_map<std::type_index, std::shared_ptr<BasicSystem>> systems;
        std::set<Entity> entitiesToBeAdded;
        std::set<Entity> entitiesToBeDestroyed;

    public:
        Registry();
        ~Registry();

        void Update();
        Entity CreateEntity();
        void AddEntityToSystems(Entity e);

        // Components
        template <typename C, typename ...CArgs> void AddComponent(Entity e, CArgs&& ...args);
        template <typename C> void RemoveComponent(Entity e);
        template <typename C> bool HasComponent(Entity e) const;

        // Systems
        template <typename S, typename ...SArgs> void AddSystem(BasicSystem s, SArgs&& ...args);
        template <typename S> void RemoveSystem();
        template <typename S> bool HasSystem() const;
        template <typename S> S& GetSystem() const;
};

template <typename C, typename ...CArgs> void Registry::AddComponent(Entity e, CArgs&& ...args) {
    const auto componentId = Component<C>::GetId();
    const auto entityId = e.GetId();

    if (componentId >= componentPools.size()) {
        componentPools.resize(componentId + 1, nullptr);
    }

    if (!componentPools[componentId]) {
        // Pool<C>* newComponentPool = new Pool<C>();
        std::shared_ptr<Pool<C>> newComponentPool = std::make_shared<Pool<C>>();
        componentPools[componentId] = newComponentPool;
    }

    // Pool<C>* componentPool = componentPools[componentId];
    std::shared_ptr<Pool<C>> componentPool = std::static_pointer_cast<Pool<C>>(componentPools[componentId]);
    if (entityId >= componentPool->GetSize()) {
        componentPool->Resize(numEntities);
    }

    C newComponent(std::forward<CArgs>(args)...);
    componentPool->Set(entityId, newComponent);
    entityComponentSignatures[entityId].set(componentId);
}

template <typename C> void Registry::RemoveComponent(Entity e) {
    const auto componentId = Component<C>::GetId();
    const auto entityId = e.GetId();

    entityComponentSignatures[entityId].set(componentId, false);
}

template <typename C> bool Registry::HasComponent(Entity e) const {
    const auto componentId = Component<C>::GetId();
    const auto entityId = e.GetId();

    return entityComponentSignatures[entityId].test(componentId);
}

template <typename S, typename ...SArgs> void Registry::AddSystem(BasicSystem s, SArgs &&...args) {
    std::shared_ptr<S> newSystem = std::make_shared<S>(std::forward<SArgs>(args)...);
    systems.insert(std::make_pair(std::type_index(typeid(S)), newSystem));
}

template <typename S> void Registry::RemoveSystem() {
    auto system = systems.find(std::type_index(typeid(S)));
    systems.erase(system);
}

template <typename S> bool Registry::HasSystem() const {
    return systems.find(std::type_index(typeid(S))) != systems.end();
}

template <typename S> S& Registry::GetSystem() const {
    auto system = systems.find(std::type_index(typeid(S)));
    return *(std::static_pointer_cast<S>()(system->second));
}