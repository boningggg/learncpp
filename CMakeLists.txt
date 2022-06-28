# run cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -B build
# then run cmake --build build
cmake_minimum_required(VERSION 3.22)

# set the project name and version
project(learncpp VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(learnfile src/learnfile.cpp)
add_executable(learncontainer src/learn-stl/learn-container.cpp)
add_executable(learnalgorithms src/learn-stl/learn-algorithms.cpp)
add_executable(learn-overload-operator src/learn-overload/learn-overload-operator.cpp)
add_executable(test src/test.cpp)
