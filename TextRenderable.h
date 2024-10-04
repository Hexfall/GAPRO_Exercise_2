#pragma once

#include <Renderable.h>
#include <GameObject.h>
#include <string.h>

struct TextRenderable : Renderable {
private:
    std::string value;
public:
    TextRenderable(GameObject* go);
    void Render();
    void SetValue(std::string s);
    std::string GetValue();
};