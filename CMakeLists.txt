cmake_minimum_required(VERSION 3.17)
project(TCP_IP)

find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 17)

file(GLOB HEADERS "src/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(TCP_IP main.cpp ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})