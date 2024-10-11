#include <Apple.h>

void Apple::Init() {
    this->gameObject->engine->AddRenderable(this->icon);
    this->icon->SetValue("@");
    this->Relocate();
}

void Apple::Relocate() {
    this->gameObject->position.x = std::rand() % this->gameObject->engine->frame_x;
    this->gameObject->position.y = std::rand() % this->gameObject->engine->frame_y;
}
