cmake_minimum_required(VERSION 3.20)
project(Сave_Adventure)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cave_Adventure main.cpp Game.h GamePlay.h Equipment.h Heroes.h Locations.h Monsters.h Data.h Interface.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static -static-libgcc")