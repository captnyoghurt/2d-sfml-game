cmake_minimum_required(VERSION 3.1)

project(game)

set(CMAKE_CXX_STANDARD 17)

# Set names
set(Srcdir "src")
set(EXECUTABLE_NAME game)


# SFML
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)


### SOURCES
# Animation
add_subdirectory(${Srcdir}/Animation)


# Battle
add_subdirectory(${Srcdir}/Battle)


# Database
add_subdirectory(${Srcdir}/Database)


# Error
add_subdirectory(${Srcdir}/Error)


# Event
add_subdirectory(${Srcdir}/Event)


# Items
add_subdirectory(${Srcdir}/Items)


# Map
add_subdirectory(${Srcdir}/Map)


# Menu
add_subdirectory(${Srcdir}/Menu)


# Sound
add_subdirectory(${Srcdir}/Sound)


# Team
add_subdirectory(${Srcdir}/Team)


# Root sources 
set(Root_Srcs
    ${Srcdir}/constants.cpp
    ${Srcdir}/constants.h
    ${Srcdir}/initialization.cpp
    ${Srcdir}/initialization.h
    ${Srcdir}/Game.cpp
    ${Srcdir}/Game.h
    ${Srcdir}/main.cpp
)

# Create exe
add_executable(${EXECUTABLE_NAME}
    ${Animation_Srcs}
    ${Battle_Srcs}
    ${Database_Srcs}
    ${Error_Srcs}
    ${Event_Srcs}
    ${Items_Srcs}
    ${Map_Srcs}
    ${Menu_Srcs}
    ${Sound_Srcs}
    ${Team_Srcs}

    ${Root_Srcs}
)

# SFML
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Resources
file(COPY "${CMAKE_SOURCE_DIR}/data" DESTINATION .)