#pragma once

#include <Component.h>
#include <TextRenderable.h>
#include <Initable.h>
#include <Inputable.h>
#include <Updateable.h>

#include <random>

struct SnakeBody : Component, Updateable, Initable, Inputable {
private:
    SnakeBody* next;
    TextRenderable renderable;
    bool isFlipped = false;

public:
    SnakeBody(GameObject* go);
    void Update(std::chrono::duration<double> deltaTime);
    void Init();
    void Move(bool addNew);
    void HandleInput(InputEvent inputEvent);
};
