#include "Registry.hpp"

Entity Registry::CreateEntity() {
    int entityId = numEntities++;
    if (entityId >= entityComponentSignatures.size()) {
        entityComponentSignatures.resize(entityId + 1);
    }

    Entity e(entityId);
    entitiesToBeAdded.insert(e);
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