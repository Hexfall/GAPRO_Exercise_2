#pragma once

#include <chrono>
#include <random>
#include <vector>
#include <functional>
#include <map>
#include <cstring>
#include <iterator>
#include <utility>
#include <memory>

#include <ITUGames.h>
#include <InputManager.h>
#include <Initable.h>
#include <Renderable.h>
#include <Updateable.h>

struct Component;
struct GameObject;

struct Engine {
private:
    int frame_cap = 240;

    std::chrono::duration<double> frame_cap_ms;

    bool quit = false;

    std::vector<char> frame;
    std::vector<char> frame_last;
    std::vector<std::shared_ptr<Initable>>   initables;
    std::vector<std::shared_ptr<Renderable>> renderables;
    std::vector<std::shared_ptr<Updateable>> updateables;
    std::vector<std::shared_ptr<GameObject>> gameObjects;

public:
    std::chrono::time_point<std::chrono::steady_clock> time_start;
    std::chrono::time_point<std::chrono::steady_clock> time_end;
    std::chrono::time_point<std::chrono::steady_clock> time_end_computation;
    std::chrono::duration<double>                      time_elapsed;
    std::chrono::duration<double>                      time_computation;

    double GetFPS();
    double GetTimeElapsedMs();
    double GetTimeComputationMs();

    int frame_x;
    int frame_y;

    void GameLoop();
    void Init();
    void ProcessEvent();
    void Update();
    void Render();
    void SetFrameChar(char c, int x, int y);
    void HandleInitables();
    void AddInitable(std::shared_ptr<Initable> i);
    void AddRenderable(std::shared_ptr<Renderable> r);
    void AddUpdateable(std::shared_ptr<Updateable> u);
    std::shared_ptr<GameObject> CreateGameObject();

    void Quit();

    InputManager inputManager;
};

#include <GameObject.h>
