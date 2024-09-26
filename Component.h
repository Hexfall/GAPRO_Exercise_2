#pragma once

#include <GameObject.h>

struct Component {
private:
    GameObject* gameObject;
    int count;

public:
    Component(GameObject* go);
    void Init();
    void SubscribeToInput(char c, void (Component::* func)());
    void IncrementW();
};
