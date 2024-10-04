#pragma once

#include <Component.h>
#include <TextRenderable.h>

struct SnakeBody : Component {
private:
    SnakeBody* next;
    TextRenderable renderable;

public:
    //TODO: uncomment  and implement better Init
    //using Component::Component;
    SnakeBody(struct GameObject* go);
    void Init();
    void Render();
    void Move(bool add_new);
};
