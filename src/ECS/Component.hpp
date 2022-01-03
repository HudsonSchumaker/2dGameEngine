#ifndef Component_hpp
#define Component_hpp

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

#endif /* Component_hpp */