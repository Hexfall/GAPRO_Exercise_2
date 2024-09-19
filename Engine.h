#pragma once

#include <chrono>
#include <random>
#include <vector>
#include <cstring>
#include <iterator>

#include <ITUGames.h>

struct Engine {
private:
    int frame_cap = 240;

    std::chrono::duration<double> frame_cap_ms;

    bool quit = false;

    char frame_empty[40][40];
    char frame[40][40];
    char frame_last[40][40] ;

    int frame_x;
    int frame_y;

public:
    std::chrono::time_point<std::chrono::steady_clock> time_start;
    std::chrono::time_point<std::chrono::steady_clock> time_end;
    std::chrono::time_point<std::chrono::steady_clock> time_end_computation;
    std::chrono::duration<double>                      time_elapsed;
    std::chrono::duration<double>                      time_computation;

    double GetFPS();
    double GetTimeElapsedMs();
    double GetTimeComputationMs();

    void GameLoop();
    void Init();
    void ProcessEvent();
    void Update();
    void Render();
};
