#pragma once

#include <Engine.h>

struct GameObject {
private:
    Engine* engine;
    int count;

public:
    GameObject(Engine* e);
    void IncrementW();
};
