cmake_minimum_required(VERSION 3.16)

add_library(
Seed
  STATIC
    Seed.cpp
  SeedSunflower.cpp
 SeedCherrybomb.cpp
SeedPeashooter.cpp
SeedRepeater.cpp
SeedWallnut.cpp
Shovel.cpp
)

target_link_libraries(
  GameObject
Seed
 GameWorld
  Framework
)
