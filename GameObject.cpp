#include <GameObject.h>

GameObject::GameObject(Engine* e) {
    this->engine = e;
}

template <class T>
T* GameObject::GetComponent() {
    for (Component* c : this->components) {
        T* TInstance = dynamic_cast<T*>(c);
        if (TInstance != nullptr)
            return TInstance;
    }
    return nullptr;
}

void GameObject::AddComponent(Component *c) {
    this->components.push_back(c);
}
