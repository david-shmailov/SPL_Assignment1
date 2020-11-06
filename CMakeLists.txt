cmake_minimum_required(VERSION 3.10)
project(SPL_Assignment1)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        include/Agent.h
        include/Graph.h
        include/json.hpp
        include/Session.h
        include/Tree.h
        )
set(PROJECT_SOURCES
        src/main.cpp
        src/Agent.cpp
        src/Graph.cpp
        src/Session.cpp
        src/Tree.cpp
        )

add_executable(SPL_Assignment1 ${PROJECT_SOURCES} ${PROJECT_HEADERS})
