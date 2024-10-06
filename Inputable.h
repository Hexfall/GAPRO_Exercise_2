#pragma once

struct InputEvent {
    char key;
    InputEvent(char key) {
        this->key = key;
    }
};

struct Inputable {
    virtual void HandleInput(InputEvent inputEvent) {};
};
