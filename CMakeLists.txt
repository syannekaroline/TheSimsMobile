cmake_minimum_required(VERSION 3.0)
project(TheSimsProject)

set(SOURCES
    src/main.cpp
    src/Sims.cpp
    src/SimsHouse.cpp
    src/SimsAppearance.cpp
    src/SimsGame.cpp
    src/Data.cpp
    src/Quests.cpp
    src/DailyTasks.cpp
    src/GeneralMissions.cpp
    src/Stories.cpp
    src/StoriesRelationship.cpp
    src/FriendshipActions.cpp
    src/RomanticActions.cpp
    src/StoriesCareer.cpp
    src/QuickShift.cpp
    src/StandardShift.cpp

    # Adicione mais arquivos fonte se você tiver mais classes
)

add_executable(meuprograma ${SOURCES})
target_include_directories(meuprograma PRIVATE include)