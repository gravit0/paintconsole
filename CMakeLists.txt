﻿cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(paintconsole)
#add_executable(${PROJECT_NAME} "src/main.cpp" "src/boost-server.cpp" "src/utils.cpp" "src/basecmds.cpp" "src/testcmds.cpp" "src/basefuncions.cpp" "src/service.cpp" "src/tcpclient.cpp" "src/memcached.cpp")
set( SOURCE_ROOT ./src )
aux_source_directory( ${SOURCE_ROOT} SOURCES )
add_executable(${PROJECT_NAME} ${SOURCES})
# Собираем файлы с текущего каталога
#file(GLOB TARGET_SRC "CMAKE_CURRENT_SOURCE_DIR/src/*.cpp")
# Добавляем исполняемый файл
#add_executable(${TARGET} ${TARGET_SRC})
#include_directories(./src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2")
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#find_package(Boost COMPONENTS system filesystem REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} pthread)
