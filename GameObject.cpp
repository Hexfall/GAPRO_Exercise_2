#include <GameObject.h>

GameObject::GameObject(Engine* e) : components() {
    this->engine = e;
    this->loc_x = 0;
    this->loc_y = 0;
}
