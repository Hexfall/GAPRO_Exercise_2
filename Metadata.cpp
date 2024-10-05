#include <Metadata.h>

Metadata::Metadata(GameObject *go)
    : Component(go), label(go) {
    this->gameObject->engine->AddInitable(this);
}

void Metadata::Init() {
    this->gameObject->engine->AddRenderable(&this->label);
    this->gameObject->engine->AddUpdateable(this);
}

void Metadata::Update(std::chrono::duration<double> deltaTime) {
    this->label.SetValue("FPS : " + std::to_string(this->gameObject->engine->GetFPS()));
}
