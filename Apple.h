#pragma once

#include <Component.h>
#include <TextRenderable.h>

#include <random>
#include <memory>

struct Apple : Component, Initable {
public:
    Apple(GameObject* go): Component(go), icon(new TextRenderable(go)) {}
    std::shared_ptr<TextRenderable> icon;
    void Init();
    void Relocate();
};
