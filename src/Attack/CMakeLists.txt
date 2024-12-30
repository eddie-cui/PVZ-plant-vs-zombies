cmake_minimum_required(VERSION 3.16)

add_library(
Attack
  STATIC
   Explosion.cpp
Pea.cpp
Attack.cpp
)

target_link_libraries(
  GameObject
Attack
 GameWorld
  Framework
)
