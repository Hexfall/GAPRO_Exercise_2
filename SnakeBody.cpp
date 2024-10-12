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

void SnakeBody::Move(float x, float y, bool addNew) {
    if (this->hasNext) {
        this->next->Move(this->gameObject->position.x, this->gameObject->position.y, addNew);
    } else if (addNew) {
        auto go = this->gameObject->engine->CreateGameObject();
        this->next = go->AddComponent<SnakeBody>();
        this->next->Move(this->gameObject->position.x, this->gameObject->position.y, false);
        this->hasNext = true;
    }
    this->gameObject->SetPosition(glm::vec2(x, y));
}

bool SnakeBody::Collides(glm::vec3 v) {
    if (this->gameObject->position.x == v.x && this->gameObject->position.y == v.y)
        return true;
    if (this->hasNext)
        return this-next->Collides(v);
    return false;
}
