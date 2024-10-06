#include <InputManager.h>

void InputManager::HandleInput() {
    char c = char(std::tolower(ITUGames::Console::GetCharacter()));

    auto res = this->keyCallbacks.find(c);
    if (res != this->keyCallbacks.end()) {
        InputEvent event(c);
        for (auto inputable : res->second) {
            inputable->HandleInput(event);
        }
    }
}

void InputManager::Subscribe(char c, Inputable* inputable) {
    c = char(std::tolower(c));
    auto res = this->keyCallbacks.find(c);
    if (res == this->keyCallbacks.end()) {
        this->keyCallbacks[c] = std::vector<Inputable*>();
        res = this->keyCallbacks.find(c);
    }

    res->second.push_back(inputable);
}
