#include "Registry.hpp"
#include "../Log/Logger.hpp"

Registry::Registry() {
    Logger::Engine("Registry created.");
}

Registry::~Registry() {
    Logger::Engine("Registry destroyed.");
}

void Registry::Update() {
    for(auto entity : entitiesToBeAdded) {
        AddEntityToSystems(entity);
    }
    entitiesToBeAdded.clear();
}

Entity Registry::CreateEntity() {
    int entityId = numEntities++;
    if (entityId >= entityComponentSignatures.size()) {
        entityComponentSignatures.resize(entityId + 1);
    }

    Entity e(entityId);
    entitiesToBeAdded.insert(e);
    Logger::Engine("Entity created with id = " + std::to_string(entityId));
    return e;
}

void Registry::AddEntityToSystems(Entity e) {
    const auto entityId = e.GetId();
    const auto& entityComponentSignature = entityComponentSignatures[entityId];

    for(auto& system : systems) {
        const auto& systemComponentSignature = system.second->GetComponentSignature();

        // black magic
        bool isInterested = (entityComponentSignature & systemComponentSignature) == systemComponentSignature;

        if (isInterested) {
            system.second->AddEntityToSystem(e);
        }
    }
}