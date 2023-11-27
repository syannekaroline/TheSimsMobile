cmake_minimum_required(VERSION 3.0)
project(TheSimsProject)

set(SOURCES
    src/main.cpp
    src/Sims.cpp
    src/SimsGame.cpp
    src/SimsAppearance.cpp
    src/Data.cpp
    src/hierarquiaQuests/Quests.cpp
    src/hierarquiaQuests/DailyTasks.cpp
    src/hierarquiaQuests/GeneralMissions.cpp
    src/hierarquiaStories/Stories.cpp
    src/hierarquiaStories/StoriesNivel2/RelationshipStories.cpp
    src/hierarquiaStories/StoriesNivel2/CareerStories.cpp

    src/hierarquiaStories/RelationshipsStories/FriendshipActions.cpp
    src/hierarquiaStories/RelationshipsStories/RomanticActions.cpp

    src/hierarquiaLocation/Location.cpp
    src/hierarquiaLocation/Building.cpp
    src/hierarquiaLocation/Workplace.cpp
    src/hierarquiaLocation/LeisurePlace.cpp
    src/hierarquiaLocation/SimsHouse.cpp
    src/infosGame.txt
    # Adicione mais arquivos fonte se você tiver mais classes
)

add_executable(meuprograma ${SOURCES})

target_include_directories(meuprograma PRIVATE include)