cmake_minimum_required(VERSION 3.10)
project(MyApp)


file(GLOB SOURCES_SQLITE ${SOURCE_DIR}/sqlite/src/*.c)

add_library(
    sqlite3
    "sqlite/sqlite3.c"
    # ${SOURCES_SQLITE}
)

include_directories(sqlite)
include_directories(include)

add_executable(Binary src/main.cpp)
target_link_libraries(Binary sqlite3)
