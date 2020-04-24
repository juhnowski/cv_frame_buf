cmake_minimum_required(VERSION 2.8)
project( sun_cv )
find_package( OpenCV REQUIRED
        PATHS )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( sun_cv
        main.cpp
        image_header.h)
target_link_libraries( sun_cv ${OpenCV_LIBS} )