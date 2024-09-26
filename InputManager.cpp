#include <InputManager.h>

void InputManager::HandleInput() {
    char c = char(std::tolower(ITUGames::Console::GetCharacter()));

    auto res = this->keyCallbacks.find(c);
    if (res != this->keyCallbacks.end()) {
        for (auto p : res->second) {
            (*p.first.*p.second)();
        }
    }
}

void InputManager::Subscribe(char c, Component &go, void (Component::*func)()) {
    c = char(std::tolower(c));
    auto res = this->keyCallbacks.find(c);
    if (res == this->keyCallbacks.end()) {
        this->keyCallbacks[c] = std::vector<std::pair<Component*, void (Component::*)()>>();
        res = this->keyCallbacks.find(c);
    }

    res->second.push_back(std::make_pair(&go, func));
}
