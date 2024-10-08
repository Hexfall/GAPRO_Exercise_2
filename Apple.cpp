#include <Apple.h>

Apple::Apple(GameObject *go)
    : Component(go), icon(go) {
    this->gameObject->engine->AddInitable(this);
}

void Apple::Init() {
    this->gameObject->engine->AddRenderable(&this->icon);
    this->icon.SetValue("@");
    this->Relocate();
}

void Apple::Relocate() {
    this->gameObject->loc_x = std::rand() % this->gameObject->engine->frame_x;
    this->gameObject->loc_y = std::rand() % this->gameObject->engine->frame_y;
}
