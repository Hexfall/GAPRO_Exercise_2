#pragma once

#include <ITUGames.h>
#include <Inputable.h>

#include <map>
#include <functional>
#include <vector>
#include <cstring>
#include <utility>

struct Component;

struct InputManager {
private:
    std::map<char, std::vector<Inputable*>> keyCallbacks;

public:
    void Subscribe(char c, Inputable* inputable);
    void HandleInput();
};
