#pragma once

#include <GameObject.h>
#include <Component.h>
#include <Initable.h>
#include <Updateable.h>
#include <TextRenderable.h>
#include <chrono>
#include <format>
#include <memory>

struct Metadata : Component, Initable, Updateable {
private:
    std::shared_ptr<TextRenderable> label;

public:
    Metadata(GameObject* go): Component(go), label(new TextRenderable(go)) {}
    void Init();
    void Update(std::chrono::duration<double> deltaTime);
};
