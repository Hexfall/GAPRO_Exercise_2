#include <Metadata.h>

void Metadata::Init() {
    this->gameObject->engine->AddRenderable(&this->label);
    this->gameObject->engine->AddUpdateable(this);
}

void Metadata::Update(std::chrono::duration<double> deltaTime) {
    this->label.SetValue("FPS : " + std::to_string(this->gameObject->engine->GetFPS()));
}
