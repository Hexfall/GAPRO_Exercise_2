#include <GameObject.h>

GameObject::GameObject(Engine* e) {
    this->engine = e;
    this->loc_x = 0;
    this->loc_y = 0;
}

void GameObject::AddComponent(Component *c) {
    this->components.push_back(c);
}
