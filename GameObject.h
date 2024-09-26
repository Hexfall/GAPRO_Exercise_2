#pragma once

#include <Engine.h>
#include <vector>

struct Component;

struct GameObject {
private:
    std::vector<Component*> components;

public:
    Engine* engine;
    GameObject(Engine* e);
    template <class T>
    T* GetComponent();
    void AddComponent(Component *c);
};
