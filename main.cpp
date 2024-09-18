#include <iostream>
#include <chrono>
#include <random>

#include "ITUGames.h"

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

#define FRAME_CAP 60
#define FRAME_CAP_MS std::chrono::duration<double>(1.0/FRAME_CAP)

void LongComputation();
void RenderText(std::string text, int x, int y);

int main() {
	// setup
	std::srand(std::time(nullptr)); // initializes random generator

	while (true) {
		time_start = std::chrono::steady_clock::now();
        ITUGames::Console::ClearScreen();

		LongComputation();

		time_end = std::chrono::steady_clock::now();
        computation_time = time_end - time_start;



        RenderText("Elapsed : " + std::to_string(frame_time.count() * 1000) + "ms", 1, 0);
        RenderText("FPS     : " + std::to_string(1.0 / frame_time.count()), 1, 2);
		ITUGames::Utils::PreciseSleep(FRAME_CAP_MS - computation_time);

        frame_time = std::chrono::steady_clock::now() - time_start;
	}

	return 0;
}

void RenderText(std::string text, int x, int y) {
    for (int i = 0; i < text.length(); i++) {
        ITUGames::Console::RenderCharacter(text[i], x+i, y);
    }
}

void LongComputation() {
	// get a random number between 0.01 and 0.016
	double sleep_time = (10 + std::rand() % 6) / 1000;

	ITUGames::Utils::PreciseSleep(std::chrono::duration<double>(sleep_time));
}