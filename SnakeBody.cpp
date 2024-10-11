#include <SnakeBody.h>

void SnakeBody::Init() {
    this->renderable->SetValue("O");
    this->gameObject->engine->AddRenderable(this->renderable);
    this->gameObject->engine->AddUpdateable(
            std::dynamic_pointer_cast<Updateable>(this->gameObject->GetComponent<typeof(*this)>()));
}

void SnakeBody::Update(std::chrono::duration<double> deltaTime) {
    if (std::rand() % 500 == 0) {
        this->isFlipped = !this->isFlipped;
        this->renderable->SetValue(this->isFlipped ? "0" : "O");
    }
}

void SnakeBody::Move(glm::vec3 newPos, bool addNew) {
    if (this->next) {
        this->next->Move(this->gameObject->position, false);
    } else if (addNew) {
        auto go = this->gameObject->engine->CreateGameObject();
        go->SetPosition(this->gameObject->position);
        this->next = go->AddComponent<SnakeBody>();
    }
    this->gameObject->SetPosition(newPos);
}
