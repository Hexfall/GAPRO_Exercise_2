#pragma once

#include <Engine.h>
#include <Initable.h>
#include <vector>
#include <memory>

struct Component;

struct GameObject {
private:
    std::vector<std::shared_ptr<Component>> components;

public:
    int loc_x;
    int loc_y;
    Engine* engine;
    GameObject(Engine* e);
    template <typename T>
    std::shared_ptr<T> GetComponent();
    template <typename T>
    std::shared_ptr<T> AddComponent();
    template <typename T>
    void RemoveComponent();
};

#include <Component.h>

template <typename T>
inline std::shared_ptr<T> GameObject::GetComponent() {
    std::cout << "\nthere are " << this->components.size() << " components\n";
    for (int i = 0; i < this->components.size(); i++) {
        auto TInstance = std::dynamic_pointer_cast<T>(this->components[i]);
        if (TInstance)
            return TInstance;
    }
    return nullptr;
}

template <typename T>
inline std::shared_ptr<T> GameObject::AddComponent() {
    if (this->GetComponent<T>())
        // GameObject already has a component of this type.
        return nullptr;

    int index = this->components.size();

    this->components.emplace_back(new T(this));

    return std::dynamic_pointer_cast<T>(this->components[index]);
}

template <typename T>
inline void GameObject::RemoveComponent() {
    for (int i = 0; i < this->components.size(); i++) {
        auto TInstance = std::dynamic_pointer_cast<T>(this->components[i]);
        if (TInstance) {
            this->components.erase(std::next(this->components.begin(), i));
            break;
        }
    }
}
