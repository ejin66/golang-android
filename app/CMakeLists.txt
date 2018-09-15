# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

#设置cmake支持的最小版本
cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

#设置生成的so动态库最后输出的路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/jni/${ANDROID_ABI})

#头文件路径
include_directories("src/main/jniLibs/include")

#配置文件
file(GLOB native_srcs "src/main/jniLibs/*.c")

#配置生成的so库的配置。
#第一次参数：生产的so库名称
#第二个参数：生成的so库的类型，SHARED代表动态链接库.so，STATIC代表静态库.a
#第三个开始的参数：生成库所包括的代码文件。可以枚举，也可以用上面定义的文件集合：{native_srcs}
add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             ${native_srcs} )

add_library(godemo
            SHARED
            IMPORTED
)

set_target_properties(godemo
                    PROPERTIES IMPORTED_LOCATION
                    ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libgodemo.so
)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

#查找库。
#第一个参数：定义变量名，表示查找的库
#第二个参数：需要查找的本地库
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

#关联本地库到目标生成库
target_link_libraries( # Specifies the target library.
                       native-lib

                       ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libgodemo.so
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )