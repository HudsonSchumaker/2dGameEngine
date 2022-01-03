#ifndef Entity_hpp
#define Entity_hpp

#include "Registry.hpp"

class Entity final {
    private:
        int id;

    public:
        Entity(int id): id(id) {};
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

       // class Registry* registry; // do better
};

template <typename C, typename ...CArgs> void Entity::AddComponent(CArgs&& ...args) {
    Registry::getInstance().AddComponent<C>(*this, std::forward<CArgs>(args)...);
}

template <typename C> void Entity::RemoveComponent() {
    //Registry::getInstance().RemoveComponent<C>(*this);
}

template <typename C> bool Entity::HasComponent() const {
    return false; //Registry::getInstance()::HasComponent<C>(*this);
}

template <typename C> C& Entity::GetComponent() const {
    return nullptr;// Registry::getInstance().GetComponent<C>(*this);
}

#endif /* Entity_hpp */