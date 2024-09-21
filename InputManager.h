#pragma once

#include <ITUGames.h>

#include <map>
#include <functional>
#include <vector>
#include <cstring>
#include <utility>

struct GameObject;

struct InputManager {
private:
    std::map<char, std::vector<std::pair<GameObject*, void (GameObject::*)()>>> keyCallbacks;

public:
    void Subscribe(char c, GameObject& go, void (GameObject::* func)());
    void HandleInput();
};
