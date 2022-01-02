#pragma once
#include <bitset>

const unsigned int MAX_COMPONENTS = 16;
typedef std::bitset<MAX_COMPONENTS> Signature;

struct IComponent {
    protected:
        static int nextId;
};

template <typename T> class Component: public IComponent {
    public:
        static int GetId() {
            static auto id = nextId++;
            return id;
        }
};