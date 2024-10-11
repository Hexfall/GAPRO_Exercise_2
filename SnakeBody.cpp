#include <SnakeBody.h>

void SnakeBody::Init() {
    this->renderable.SetValue("O");
    this->gameObject->engine->AddRenderable(&this->renderable);
    this->gameObject->engine->AddUpdateable(this);
    this->gameObject->engine->inputManager.Subscribe('w', this);
    this->gameObject->engine->inputManager.Subscribe('a', this);
    this->gameObject->engine->inputManager.Subscribe('s', this);
    this->gameObject->engine->inputManager.Subscribe('d', this);
}

void SnakeBody::Update(std::chrono::duration<double> deltaTime) {
    if (std::rand() % 500 == 0) {
        this->isFlipped = !this->isFlipped;
        this->renderable.SetValue(this->isFlipped ? "0" : "O");
    }
}

void SnakeBody::Move(bool addNew) {
    this->gameObject->loc_x += 1;
}

void SnakeBody::HandleInput(InputEvent inputEvent) {
    switch (inputEvent.key) {
        case 'w':
            this->gameObject->loc_y--;
            break;
        case 'a':
            this->gameObject->loc_x--;
            break;
        case 's':
            this->gameObject->loc_y++;
            break;
        case 'd':
            this->gameObject->loc_x++;
            break;
    }
}
