cmake_minimum_required(VERSION 3.24)
project(tic_tac)

set(CMAKE_CXX_STANDARD 17)

set(SFML_LIBRARY_G /usr/lib/x86_64-linux-gnu/libsfml-graphics.so)
set(SFML_LIBRARY_W /usr/lib/x86_64-linux-gnu/libsfml-window.so)
set(SFML_LIBRARY_S /usr/lib/x86_64-linux-gnu/libsfml-system.so)

add_executable(tic_tac
                main.cpp
                Game/Game.cpp Game/Game.h
                Game/Background/Background.cpp Game/Background/Background.h
                Game/GameObjects/Grid/Grid.cpp Game/GameObjects/Grid/Grid.h
                Game/GameObjects/gameObject.cpp Game/GameObjects/gameObject.h
                Game/GameObjects/O_obj/O_obj.cpp Game/GameObjects/O_obj/O_obj.h
                Game/GameObjects/X_obj/X_obj.cpp Game/GameObjects/X_obj/X_obj.h
                Game/Text/Text.cpp)

target_link_libraries(tic_tac ${SFML_LIBRARY_G} ${SFML_LIBRARY_W} ${SFML_LIBRARY_S})
