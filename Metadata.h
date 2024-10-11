#pragma once

#include <GameObject.h>
#include <Component.h>
#include <Initable.h>
#include <Updateable.h>
#include <TextRenderable.h>
#include <chrono>
#include <format>

struct Metadata : Component, Initable, Updateable {
private:
    TextRenderable label;

public:
    Metadata(GameObject* go): Component(go), label(go) {}
    void Init();
    void Update(std::chrono::duration<double> deltaTime);
};
