#include <SnakeHead.h>

void SnakeHead::Init() {
    this->snakeBody = this->gameObject->GetComponent<SnakeBody>();
    this->gameObject->engine->AddUpdateable(
            std::dynamic_pointer_cast<Updateable>(this->gameObject->GetComponent<typeof(*this)>()));
    this->gameObject->engine->inputManager.Subscribe('w', this);
    this->gameObject->engine->inputManager.Subscribe('a', this);
    this->gameObject->engine->inputManager.Subscribe('s', this);
    this->gameObject->engine->inputManager.Subscribe('d', this);
}

void SnakeHead::HandleInput(InputEvent inputEvent) {
    switch (inputEvent.key) {
        case 'w':
            this->direction = glm::vec2(0, -1);
            break;
        case 'a':
            this->direction = glm::vec2(-1, 0);
            break;
        case 's':
            this->direction = glm::vec2(0, 1);
            break;
        case 'd':
            this->direction = glm::vec2(1, 0);
            break;
    }
}

void SnakeHead::Update(std::chrono::duration<double> deltaTime) {
    //std::cout << this->timeSinceLastMove.count();
    this->timeSinceLastMove += deltaTime;
    if (this->timeSinceLastMove > this->timeBetweenMoves) {
        this->timeSinceLastMove -= this->timeBetweenMoves;
        this->Move();
    }
}

void SnakeHead::Move() {
    glm::mat3 m(1.0f);
    m[2][0] = this->direction.x;
    m[2][1] = this->direction.y;
    glm::vec3 v = m * this->gameObject->position;
    this->snakeBody->Move(v, true);
}

void SnakeHead::SetApple(std::shared_ptr<Apple> apple) {
    this->apple = apple;
}
