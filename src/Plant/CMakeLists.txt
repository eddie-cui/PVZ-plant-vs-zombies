cmake_minimum_required(VERSION 3.16)

add_library(
 Plant
  STATIC
   Plant.cpp
  SunFlower.cpp
 Wallnut.cpp
Cherrybomb.cpp
Repeater.cpp
Peashooter.cpp
)

target_link_libraries(
  GameObject
Plant
 GameWorld
  Framework
)
