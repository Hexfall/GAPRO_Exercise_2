#pragma once

#include <Component.h>
#include <TextRenderable.h>
#include <Initable.h>
#include <Inputable.h>
#include <Updateable.h>

#include <random>

struct SnakeBody : Component, Updateable, Initable {
private:
    std::shared_ptr<SnakeBody> next;
    std::shared_ptr<TextRenderable> renderable;
    bool isFlipped = false;

public:
    SnakeBody(GameObject* go) : Component(go), renderable(new TextRenderable(go)) {this->next = nullptr;}
    void Update(std::chrono::duration<double> deltaTime);
    void Init();
    void Move(glm::vec3 newPos, bool addNew);
};
