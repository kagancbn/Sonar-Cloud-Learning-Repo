cmake_minimum_required(VERSION 3.10)
project(ImageGrayscaleConverter)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add the executable
add_executable(image_grayscale src/main.cpp)

# Link OpenCV libraries
target_link_libraries(image_grayscale ${OpenCV_LIBS})
