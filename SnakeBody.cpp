#include <SnakeBody.h>

SnakeBody::SnakeBody(struct GameObject *go)
    : Component(go), renderable(go) {
    this->renderable.SetValue("O");
    this->Init();
}

void SnakeBody::Init() {
    this->gameObject->engine->AddRenderable(&this->renderable);
}
