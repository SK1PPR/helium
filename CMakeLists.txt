cmake_minimum_required(VERSION 3.20)  # Use a realistic minimum version

project(helium)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)  # Find OpenCV

include_directories(include)

add_executable(helium
        src/main.cpp
        src/utils.cpp
        src/image.cpp
        src/video.cpp
)

target_include_directories(helium PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(helium PRIVATE ${OpenCV_LIBS})