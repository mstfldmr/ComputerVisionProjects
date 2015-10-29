cmake_minimum_required(VERSION 2.8)
project(Project1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH "/usr/local/opt/opencv3/share/OpenCV")

# set(OpenCV_INCLUDE_DIRS "/usr/local/opt/opencv3/include")
# set(OpenCV_LIBS "/usr/local/opt/opencv3/lib")


set(SOURCE_FILES buildinfo.cpp facedetect.cpp)


# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "CMake Message to Mustafa")
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# Add OpenCV headers location to your include paths
include_directories(${OpenCV_INCLUDE_DIRS})

# Declare the executable target built from your sources
#add_executable(cv_project1 facedetect.cpp Project1.cpp Project1.h)
#add_executable(cv_project1 Project1.cpp Project1.h test.cpp)
add_executable(cv_project1 test.cpp)

# Link your application with OpenCV libraries
target_link_libraries(cv_project1 ${OpenCV_LIBS})
