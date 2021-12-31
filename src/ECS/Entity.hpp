#pragma once

class Entity {
    private:
        int id;

    public:
        Entity(int id) : id(id) {};
        ~Entity();
        int GetId() const;
};