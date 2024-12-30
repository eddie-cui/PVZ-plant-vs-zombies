cmake_minimum_required(VERSION 3.16)

add_library(
Zombie
  STATIC
Zombie.cpp
PoleVaultingZombie.cpp
RegularZombie.cpp
BucketHeadZombie.cpp
)

target_link_libraries(
  GameObject
Zombie
 GameWorld
  Framework
)
