#include <Metadata.h>

void Metadata::Init() {
    this->gameObject->engine->AddRenderable(label);
    this->gameObject->engine->AddUpdateable(
            std::dynamic_pointer_cast<Updateable>(this->gameObject->GetComponent<typeof(*this)>()));
}

void Metadata::Update(std::chrono::duration<double> deltaTime) {
    this->label->SetValue("FPS : " + std::to_string(this->gameObject->engine->GetFPS()));
}
