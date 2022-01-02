#pragma once
//#include "Registry.hpp"

class Entity {
    private:
        int id;

    public:
        Entity(int id) : id(id) {};
        Entity(const Entity& entity) = default;
        ~Entity() = default;
        int GetId() const;

        Entity& operator =(const Entity& other) = default;
        bool operator ==(const Entity& other) const { return id == other.id; }
        bool operator !=(const Entity& other) const { return id != other.id; }
        bool operator >(const Entity& other) const { return id > other.id; }
        bool operator <(const Entity& other) const { return id < other.id; }

        template <typename C, typename ...CArgs> void AddComponent(CArgs&& ...args);
        template <typename C> void RemoveComponent();
        template <typename C> bool HasComponent() const;
        template <typename C> C& GetComponent() const;

        class Registry* registry; // do better
};

template <typename C, typename ...CArgs> void Entity::AddComponent(CArgs&& ...args) {
    registry->AddComponent<C>(*this, std::forward<CArgs>(args)...);
}

template <typename C> void Entity::RemoveComponent() {
    registry->RemoveComponent<C>(*this);
}

template <typename C> bool Entity::HasComponent() const {
    return registry->HasComponent<C>(*this);
}

template <typename C> C& Entity::GetComponent() const {
    return registry->GetComponent<C>(*this);
}
