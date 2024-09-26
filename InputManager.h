#pragma once

#include <ITUGames.h>

#include <map>
#include <functional>
#include <vector>
#include <cstring>
#include <utility>

struct Component;

struct InputManager {
private:
    std::map<char, std::vector<std::pair<Component*, void (Component::*)()>>> keyCallbacks;

public:
    void Subscribe(char c, Component& go, void (Component::* func)());
    void HandleInput();
};
