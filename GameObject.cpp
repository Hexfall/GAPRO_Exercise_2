#include <GameObject.h>

GameObject::GameObject(Engine* e) {
    this->engine = e;
    this->count = 0;
    this->engine->inputManager.Subscribe('w', *this, &GameObject::IncrementW);
}

void GameObject::IncrementW() {
    this->count++;
    std::cout << "inc" << this->count << std::endl;
}
