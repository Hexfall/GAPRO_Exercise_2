#include <Component.h>

Component::Component(GameObject* go) {
    this->gameObject = go;
}

Component::~Component() {
    this->gameObject->RemoveComponent<typeof(*this)>();
}

void Component::Init() {}

void Component::IncrementW() {
    this->count++;
    std::cout << "inc" << this->count << std::endl;
}
