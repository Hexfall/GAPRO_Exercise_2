#include <GameObject.h>

GameObject::GameObject(Engine* e) : components(), position(0, 0, 1) {
    this->engine = e;
}

void GameObject::Translate(float x, float y) {
    glm::mat3 m(1.0f);
    m[2][0] = x;
    m[2][1] = y;
    this->Translate(m);
}

void GameObject::Translate(glm::mat3 m) {
    this->position = m * this->position;
}

void GameObject::Translate(glm::vec2 v) {
    this->Translate(v.x, v.y);
}

void GameObject::SetPosition(glm::vec2 v) {
    this->SetPosition(glm::vec3(v, 1));
}

void GameObject::SetPosition(glm::vec3 v) {
    this->position = v;
}
