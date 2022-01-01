#pragma once

class Entity {
    private:
        int id;

    public:
        Entity(int id) : id(id) {};
        ~Entity() = default;
        int GetId() const;
};