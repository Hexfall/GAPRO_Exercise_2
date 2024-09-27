#include <Component.h>

Component::Component(GameObject* go) {
    this->gameObject = go;
    this->Init();
    auto x = go->GetComponent<typeof(*this)>();
}

Component::~Component() {
    this->gameObject->RemoveComponent<typeof(*this)>();
}

void Component::Init() {
    this->count = 0;
    this->SubscribeToInput('w', &Component::IncrementW);
}

void Component::IncrementW() {
    this->count++;
    std::cout << "inc" << this->count << std::endl;
}

void Component::SubscribeToInput(char c, void (Component::*func)()) {
    this->gameObject->engine->inputManager.Subscribe(c, *this, func);
}
