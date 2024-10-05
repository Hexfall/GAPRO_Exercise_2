# cmake_minimum_required(VERSION <specify CMake version here>)
project(Exercise_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercise_2
        Component.cpp
        Component.h
        SnakeBody.cpp
        SnakeBody.h
        Engine.cpp
        Engine.h
        GameObject.cpp
        GameObject.h
        InputManager.cpp
        InputManager.h
        ITUGames.h
        Initable.h
        Updateable.h
        Updateable.cpp
        Renderable.h
        Renderable.cpp
        TextRenderable.h
        TextRenderable.cpp
        Metadata.h
        Metadata.cpp
        main.cpp)
