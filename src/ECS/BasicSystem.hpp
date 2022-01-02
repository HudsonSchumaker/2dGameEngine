#pragma once
#include <vector>
#include "Component.hpp"
#include "Entity.hpp"

class BasicSystem {
    private:
        Signature componentSignature;
        std::vector<Entity> entities;
        
    public:
        BasicSystem() = default;
        virtual ~BasicSystem() = default;

        void AddEntityToSystem(Entity entity);
        void RemoveEntityFromSystem(Entity entity);
        std::vector<Entity> GetSystemEntities() const;
        const Signature& GetComponentSignature() const;

        template <typename T> void RequireComponent();
};

template <typename T> void BasicSystem::RequireComponent() {
    const auto componentId = Component<T>::GetId();
    componentSignature.set(componentId);
}
