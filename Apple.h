#pragma once

#include <Component.h>
#include <TextRenderable.h>

#include <random>

struct Apple : Component, Initable {
public:
    Apple(GameObject* go): Component(go), icon(go) {}
    TextRenderable icon;
    void Init();
    void Relocate();
};
