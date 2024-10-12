#pragma once

#include <Component.h>
#include <Initable.h>
#include <Inputable.h>
#include <Updateable.h>
#include <SnakeBody.h>
#include <Apple.h>

#include <glm/glm.hpp>
#include <memory>

struct SnakeHead : Component, Initable, Inputable, Updateable {
private:
    glm::vec2 direction;
    std::shared_ptr<SnakeBody> snakeBody;
    std::shared_ptr<Apple> apple;
    std::chrono::duration<double> timeBetweenMoves;
    std::chrono::duration<double> timeSinceLastMove;
public:
    SnakeHead(GameObject* gameObject)
        : Component(gameObject), direction(1, 0), timeBetweenMoves(0.25f), timeSinceLastMove(0) {}
    void Init();
    void Update(std::chrono::duration<double> deltaTime);
    void HandleInput(InputEvent inputEvent);
    void SetApple(std::shared_ptr<Apple> apple);
    void Move();
};
