#include <GameObject.h>

GameObject::GameObject(Engine* e) : components(), position(0, 0, 1) {
    this->engine = e;
}

void GameObject::Translate(float x, float y) {
    glm::mat3 m(1.0f);
    m[2][0] = x;
    m[2][1] = y;
    this->position = m * this->position;
}
