#include <Component.h>

Component::Component(GameObject* go) {
    this->gameObject = go;
    this->gameObject->AddComponent(this);
}

Component::~Component() {
    this->gameObject->RemoveComponent<typeof(*this)>();
}

void Component::Init() {}

void Component::IncrementW() {
    this->count++;
    std::cout << "inc" << this->count << std::endl;
}
