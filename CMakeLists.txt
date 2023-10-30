cmake_minimum_required(VERSION 3.0)
project(TheSimsProject)

set(SOURCES
    src/main.cpp
    src/Sims.cpp
    src/SimsHouse.cpp
    src/SimsAppearance.cpp
    src/SimsGame.cpp
    src/Data.cpp
    src/infosGame.txt

    # Adicione mais arquivos fonte se você tiver mais classes
)

add_executable(meuprograma ${SOURCES})
target_include_directories(meuprograma PRIVATE include)

