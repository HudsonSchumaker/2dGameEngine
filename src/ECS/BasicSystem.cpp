#include <algorithm>
#include "BasicSystem.hpp"

void BasicSystem::AddEntityToSystem(Entity entity) {
    entities.push_back(entity);
}

void BasicSystem::RemoveEntityFromSystem(Entity entity) {
    // This is ridiculous
    entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity other) {
        return entity.GetId() == other.GetId();   
    }), entities.end());
}

std::vector<Entity> BasicSystem::GetSystemEntities() const {
    return entities;
}

const Signature& BasicSystem::GetComponentSignature() const {
    return componentSignature;
}