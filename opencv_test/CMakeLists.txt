cmake_minimum_required(VERSION 3.8)

project("opencv_test")

#Steps:
#    1. Find library
#    2. Include library header folder (usually include)
#    3. Add executable
#    4. Link library

# Find OpenCV
find_package(OpenCV REQUIRED PATHS "C:/PROJECT/opencv/build/x64/vc15/lib")

# Include OpenCV in path
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(${PROJECT_NAME} main.cpp)

# Link library
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
