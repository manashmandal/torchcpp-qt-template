cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(torchcpp-qt-template)
set(CMAKE_PREFIX_PATH "/opt/libtorch")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_executable(torchcpp-qt-template main.cpp zz.h mainwindow.ui)
target_link_libraries(torchcpp-qt-template PRIVATE Qt5::Widgets "${TORCH_LIBRARIES}")
set_property(TARGET torchcpp-qt-template PROPERTY CXX_STANDARD 14)
