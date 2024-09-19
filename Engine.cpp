#include <Engine.h>

void LongComputation();

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

    //for (int i = 0; i < this->frame_x;i++)
        //this->frame_empty.push_back(std::vector<char>(this->frame_y, ESC));

    //this->frame_last = std::vector<std::vector<char>>(this->frame_empty);

    std::memset(this->frame_empty, ESC, sizeof this->frame_empty)

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
    LongComputation();
}

void Engine::Render() {
    // Create empty frame
    //this->frame = std::vector<std::vector<char>>(this->frame_empty);
    std::copy(std::begin(this->frame_empty), std::end(this->frame_empty), std::begin(this->frame))

    // Fill in frame
    std::string fps_string = "FPS : " + std::to_string(this->GetFPS());
    for (int i = 0; i < fps_string.length(); i++)
        frame[i][0] = fps_string.at(i);

    // Compare to old frame and update
    /*
    for (int x = 0; x < this->frame_x; x++) {
        for (int y = 0; y < this->frame_y; y++) {
            if (this->frame[x][y] != this->frame_last[x][y]) {
                // ITUGames::Console::RenderCharacter(this->frame[x][y], x+1, y+1);
            }
        }
    }*/

    // Keep copy of frame for next Render()

    //this->frame_last = std::vector<std::vector<char>>(this->frame);
}

void LongComputation() {
    // get a random number between 0.01 and 0.016
    double sleep_time = (10 + std::rand() % 6) / 1000;

    ITUGames::Utils::PreciseSleep(std::chrono::duration<double>(sleep_time));
}
