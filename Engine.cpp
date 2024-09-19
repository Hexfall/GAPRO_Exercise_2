#include <Engine.h>

double Engine::GetTimeComputationMs() {
    return this->time_computation.count();
}

double Engine::GetTimeElapsedMs() {
    return this->time_elapsed.count();
}

double Engine::GetFPS() {
    return 1.0/this->time_elapsed.count();
}

void Engine::Init() {
    this->frame_cap_ms = std::chrono::duration<double>(1.0/this->frame_cap);
    std::srand(std::time(nullptr)); // initializes random generator

    this->frame_x = ITUGames::Console::GetTerminalWidth();
    this->frame_y = ITUGames::Console::GetTerminalHeight();

    for (int i = 0; i < this->frame_x;i++)
        this->frame_empty.push_back(std::vector<char>(this->frame_y, ESC));

    std::copy(this->frame_empty.begin(), this->frame_empty.end(), this->frame_last.begin());

    ITUGames::Console::ClearScreen(); // Clears screen and primes it for game.
}

void Engine::GameLoop() {
    this->Init();

    while (!this->quit) {
        this->time_start = std::chrono::steady_clock::now();

        this->ProcessEvent();
        this->Update();
        this->Render();

        this->time_end_computation = std::chrono::steady_clock::now();
        this->time_computation = this->time_end_computation - this->time_start;

        ITUGames::Utils::PreciseSleep(this->frame_cap_ms - this->time_computation);

        this->time_end = std::chrono::steady_clock::now();
        this->time_elapsed = this->time_end - this->time_start;
    }
}

void Engine::ProcessEvent() {

}

void Engine::Update() {

}

void Engine::Render() {
    ITUGames::Console::GotoCoords(1, 1);
    std::cout << "FPS : " << this->GetFPS();
}
