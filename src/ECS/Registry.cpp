#include "Registry.hpp"

Entity Registry::CreateEntity() {
    int entityId = numEntities++;
    if (entityId >= entityComponentSignatures.size()) {
        entityComponentSignatures.resize(entityId +1);
    }

    Entity e(entityId);
    entitiesToBeAdded.insert(e);
    return e;
}