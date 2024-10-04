#pragma once

#include <Component.h>
#include <TextRenderable.h>
#include <Updateable.h>

#include <random>

struct SnakeBody : Component, Updateable {
private:
    SnakeBody* next;
    TextRenderable renderable;
    bool isFlipped = false;

public:
    //TODO: uncomment  and implement better Init
    //using Component::Component;
    SnakeBody(struct GameObject* go);
    void Update(std::chrono::duration<double> deltaTime);
    void Init();
    void Render();
    void Move(bool add_new);
};
