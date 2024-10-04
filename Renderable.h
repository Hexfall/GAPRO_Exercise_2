#pragma once

struct GameObject;

struct Renderable {
public:
    GameObject* gameObject;
    Renderable(GameObject* go);
    virtual void Render();
};
