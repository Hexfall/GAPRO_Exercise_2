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

    this->frame_y = ITUGames::Console::GetTerminalWidth();
    this->frame_x = ITUGames::Console::GetTerminalHeight();

    for (int i = 0; i < this->frame_x*this->frame_y; i++) {
        this->frame.push_back(' ');
        this->frame_last.push_back(' ');
    }

    ITUGames::Console::HideCursor();
    ITUGames::Console::ClearScreen(); // Clears screen and primes it for game.

    this->HandleInitables();
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
    this->inputManager.HandleInput();
}

void Engine::Update() {
    for (auto u: this->updateables) {
        if (u != nullptr)
            u->Update(this->time_elapsed);
    }
    this->HandleInitables();
    LongComputation();
}

void Engine::SetFrameChar(char c, int x, int y) {
    if (0 <= x && x < this->frame_x)
        if (0 <= y && y < this->frame_y)
            this->frame[y*this->frame_x + x] = c;
}

void Engine::Render() {
    // Create empty frame
    std::fill(this->frame.begin(), this->frame.end(), ' ');

    // Fill in frame
    for (auto r : this->renderables) {
        r->Render();
    }

    // Compare to old frame and update
    for (int y = 0; y < this->frame_y; y++) {
        for (int x = 0; x < this->frame_x; x++) {
            int index = this->frame_x*y + x;
            if (this->frame[index] != this->frame_last[index]) {
                ITUGames::Console::RenderCharacter(this->frame[index], x+1, y+1);
                this->frame_last[index] = this->frame[index];
            }
        }
    }
}

void Engine::HandleInitables() {
    while (!this->initables.empty()) {
        this->initables.back()->Init();
        this->initables.pop_back();
    }
}

void Engine::AddInitable(std::shared_ptr<Initable> i) {
    this->initables.push_back(i);
}

void Engine::AddRenderable(std::shared_ptr<Renderable> r) {
    this->renderables.push_back(r);
}

void Engine::AddUpdateable(std::shared_ptr<Updateable> u) {
    this->updateables.push_back(u);
}

void Engine::Quit() {
    this->quit = true;
}

void LongComputation() {
    // get a random number between 0.01 and 0.016
    double sleep_time = (10 + std::rand() % 6) / 1000;

    ITUGames::Utils::PreciseSleep(std::chrono::duration<double>(sleep_time));
}

std::shared_ptr<GameObject> Engine::CreateGameObject() {
    this->gameObjects.emplace_back(new GameObject(this));
    return this->gameObjects[this->gameObjects.size() - 1];
}
