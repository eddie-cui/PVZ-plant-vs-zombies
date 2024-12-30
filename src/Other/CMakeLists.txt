cmake_minimum_required(VERSION 3.16)

add_library(
 Other
  STATIC
    BackGround.cpp
  PlantPlace.cpp
    Sun.cpp

CoolDownMask.cpp
Gameend.cpp
)

target_link_libraries(
  GameObject
Other
 GameWorld
  Framework
)
