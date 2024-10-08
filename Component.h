#pragma once

#include <GameObject.h>

struct Component {
private:

public:
    int count;
    GameObject* gameObject;
    Component(GameObject* go);
    ~Component();
    virtual void Init();
    void IncrementW();
};
