cmake_minimum_required(VERSION 3.0.0)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME} VERSION 0.1.0)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find_package( OpenCV REQUIRED )
# message( STATUS "    version: ${OpenCV_VERSION}" )
# message( STATUS "    libraries: ${OpenCV_LIBS}" )
# include_directories( ${OpenCV_INCLUDE_DIRS} )
# link_directories( ${OpenCV_LIBRARY_DIRS} )

add_executable(${PROJECT_NAME} main.cpp)
# target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )