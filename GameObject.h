#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <Engine.h>
#include <Initable.h>
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

struct Component;
struct Transform;

struct GameObject {
private:
    std::vector<std::shared_ptr<Component>> components;

public:
    glm::vec3 position;
    Engine* engine;
    GameObject(Engine* e);
    void Translate(float x, float y);
    void Translate(glm::mat3 m);
    void Translate(glm::vec2 v);
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

    std::shared_ptr<Initable> initable = std::dynamic_pointer_cast<Initable>(this->components[index]);
    if (initable)
        this->engine->AddInitable(initable);

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
