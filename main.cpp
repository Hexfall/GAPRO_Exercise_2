#include <iostream>
#include <chrono>
#include <random>

#include "ITUGames.h"

#include <Engine.h>
#include <GameObject.h>
#include <SnakeBody.h>
#include <Metadata.h>
#include <Apple.h>

#pragma region Engine State

std::chrono::time_point<std::chrono::steady_clock>	time_start;
std::chrono::time_point<std::chrono::steady_clock>	time_end;
std::chrono::duration<double>						computation_time;
std::chrono::duration<double>                       frame_time;

#pragma endregion // Engine State

#pragma region Game State

/**
* If you are unsure how to organize the additional variables you will need for the exercise, just dump them here.We will address this in future lectures
* In the meantime, a good approach is to sort them and put the ones that relate to the same thing togheter
* - is this variable part of the game? Of the engine? ...
* - is it about input? Player state? Logging? ...
* And so on. Are some of those questions conflicting with each other? Yep, architecturing code is hard, but we'll get a hang of it.
*/

#pragma endregion // Game State

void LongComputation();
void RenderText(std::string text, int x, int y);

int main() {
    Engine engine;
    auto metadataGO = engine.CreateGameObject();
    metadataGO->AddComponent<Metadata>();
    auto appleObject = engine.CreateGameObject();
    appleObject->AddComponent<Apple>();
    auto go = engine.CreateGameObject();
    go->loc_y = 20;
    go->loc_x = 20;
    go->AddComponent<SnakeBody>();

    engine.GameLoop();

	return 0;
}

void RenderText(std::string text, int x, int y) {
    for (int i = 0; i < text.length(); i++) {
        ITUGames::Console::RenderCharacter(text[i], x+i, y);
    }
}