cmake_minimum_required(VERSION 3.0)
project(TheSimsProject)

set(SOURCES
    src/main.cpp
    src/Sims.cpp
    src/SimsHouse.cpp
    src/SimsAppearance.cpp
    # Adicione mais arquivos fonte se você tiver mais classes
)

add_executable(meuprograma ${SOURCES})
target_include_directories(meuprograma PRIVATE include)

