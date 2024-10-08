#pragma once

#include <Engine.h>
#include <Initable.h>
#include <vector>

struct Component;

struct GameObject {
private:
    std::vector<Component*> components;

public:
    int loc_x;
    int loc_y;
    Engine* engine;
    GameObject(Engine* e);
    template <typename T>
    T* GetComponent() {
        for (Component* c : this->components) {
            T* TInstance = dynamic_cast<T*>(c);
            if (TInstance != nullptr)
                return TInstance;
        }
        return nullptr;
    }
    void AddComponent(Component *c);
    template <typename T>
    void RemoveComponent() {
        for (int i = 0; i < this->components.size(); i++) {
            T* TInstance = dynamic_cast<T*>(this->components[i]);
            if (TInstance != nullptr) {
                this->components.erase(std::next(this->components.begin(), i));
                break;
            }
        }
    }
};
