#pragma once

#include <Component.h>
#include <TextRenderable.h>
#include <Initable.h>
#include <Inputable.h>
#include <Updateable.h>

#include <random>

struct SnakeBody : Component, Updateable, Initable {
private:
    std::shared_ptr<TextRenderable> renderable;
    bool isFlipped;

public:
    std::shared_ptr<SnakeBody> next;
    bool hasNext;
    SnakeBody(GameObject* go) : Component(go), renderable(new TextRenderable(go)), isFlipped(false), hasNext(false) {this->next = nullptr;}
    void Update(std::chrono::duration<double> deltaTime);
    void Init();
    void Move(float x, float y, bool addNew);
    bool Collides(glm::vec3 v);
};
