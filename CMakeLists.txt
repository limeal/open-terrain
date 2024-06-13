cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)

if (NOT raylib_FOUND)
  INCLUDE(FetchContent)

  FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz)
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    SET(raylib_FOUND TRUE)
  endif()
endif()

project (open_terrain)

#Here add you'r .cpp
file (GLOB_RECURSE open_terrain_SOURCES CONFIGURE_DEPENDS src/*.cpp)
#Here add you'r .hpp
file (GLOB_RECURSE open_terrain_HEADERS CONFIGURE_DEPENDS src/*.hpp)

set (open_terrain_INCLUDE_DIRS "")
foreach (_headerFile ${open_terrain_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND open_terrain_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES open_terrain_INCLUDE_DIRS)

set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${open_terrain_SOURCE_DIR})
add_executable(open_terrain ${open_terrain_SOURCES})
target_include_directories(open_terrain PUBLIC ${open_terrain_INCLUDE_DIRS})
target_link_libraries(open_terrain raylib)