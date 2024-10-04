#pragma once

#include <chrono>

struct Updateable {
public:
    virtual void Update(std::chrono::duration<double> deltaTime);
};
