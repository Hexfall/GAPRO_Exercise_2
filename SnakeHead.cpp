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
            if (this->lastDirection.y != 1)
                this->direction = glm::vec2(0, -1);
            break;
        case 'a':
            if (this->lastDirection.x != 1)
                this->direction = glm::vec2(-1, 0);
            break;
        case 's':
            if (this->lastDirection.y != -1)
                this->direction = glm::vec2(0, 1);
            break;
        case 'd':
            if (this->lastDirection.x != -1)
                this->direction = glm::vec2(1, 0);
            break;
    }
}

void SnakeHead::Update(std::chrono::duration<double> deltaTime) {
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

    if (this->apple->gameObject->position == v) {
        this->snakeBody->Move(v, true);
        this->apple->Relocate();
        this->timeBetweenMoves *= 0.97;
    } else {
        this->snakeBody->Move(v, false);
    }

    if (this->snakeBody->next && this->snakeBody->next->Collides(this->gameObject->position)) {
        this->gameObject->engine->Quit();
    }

    this->lastDirection = this->direction;
}

void SnakeHead::SetApple(std::shared_ptr<Apple> apple) {
    this->apple = apple;
}
