# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("opencv")

# 导入opencv头文件
include_directories(${OPENCV_HEADER_DIR})
message("=====${OPENCV_HEADER_DIR}====")

# add_library:把一个library添加到工程
add_library(
        native-lib
        SHARED
        nativelib.cpp)

# 添加一个已构建的库，使用IMPORTED

#string(REGEX REPLACE "(.*)/(.*)/(.*)" "\\1" PROJECT_INIT_PATH  ${PROJECT_SOURCE_DIR})
#message("=====${PROJECT_INIT_PATH}======")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/jniLibs)
add_library(opencv_java4 SHARED IMPORTED)
set_target_properties(opencv_java4
        PROPERTIES IMPORTED_LOCATION
        "${LIBRARY_OUTPUT_PATH}/${ANDROID_ABI}/libopencv_java4.so")
message("---------1----${LIBRARY_OUTPUT_PATH}/${ANDROID_ABI}/libopencv_java4.so--------------")
# 首个参数是target,后面的参数是item；target必须先用add_library()创建过；
target_link_libraries(
        native-lib
        opencv_java4
        jnigraphics
        log )
