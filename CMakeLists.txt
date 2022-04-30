cmake_minimum_required(VERSION 3.21)
project(TextBasedGame001)

set(CMAKE_CXX_STANDARD 14)

add_executable(TextBasedGame001 main.cpp gameEvents.cpp gameEvents.h gameTextHelper.cpp gameTextHelper.h entity.cpp entity.h player.cpp player.h menuUI.cpp menuUI.h itemHandler.cpp itemHandler.h combatUI.cpp combatUI.h beginnerEnemy.cpp beginnerEnemy.h colorConsole.cpp treasureUI.cpp treasureUI.h map.cpp map.h)
