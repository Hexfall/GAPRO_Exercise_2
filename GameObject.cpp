#include <GameObject.h>

GameObject::GameObject(Engine* e) {
    this->engine = e;
}

void GameObject::AddComponent(Component *c) {
    this->components.push_back(c);
}
