#include <SnakeBody.h>

SnakeBody::SnakeBody(struct GameObject *go)
    : Component(go), renderable(go) {
    this->renderable.SetValue("O");
    this->gameObject->engine->AddInitable(this);
}

void SnakeBody::Init() {
    this->gameObject->engine->AddRenderable(&this->renderable);
    this->gameObject->engine->AddUpdateable(this);
}

void SnakeBody::Update(std::chrono::duration<double> deltaTime) {
    if (std::rand() % 500 == 0) {
        this->isFlipped = !this->isFlipped;
        this->renderable.SetValue(this->isFlipped ? "0" : "O");
        this->Move(false);
    }
}

void SnakeBody::Move(bool addNew) {
    this->gameObject->loc_x += 1;
}
