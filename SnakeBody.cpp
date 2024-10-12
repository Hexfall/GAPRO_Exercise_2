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

void SnakeBody::Move(glm::vec3 v, bool addNew) {
    if (this->next) {
        this->next->Move(this->gameObject->position, addNew);
    } else if (addNew) {
        auto go = this->gameObject->engine->CreateGameObject();
        this->next = go->AddComponent<SnakeBody>();
        this->next->Move(this->gameObject->position, false);
    }
    this->gameObject->SetPosition(v);
}

bool SnakeBody::Collides(glm::vec3 v) {
    if (this->gameObject->position.x == v.x && this->gameObject->position.y == v.y)
        return true;
    if (this->next)
        return this-next->Collides(v);
    return false;
}
