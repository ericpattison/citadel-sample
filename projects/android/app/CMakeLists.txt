cmake_minimum_required(VERSION 3.4.1)

set(citadel_DIR ${CMAKE_SOURCE_DIR}/../../../citadel)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

include_directories(
    ${ANDROID_NDK}/sources/android/native_app_glue
    ${citadel_DIR}
)

add_library(
    citadel-sample
    SHARED
    #src/main/cpp/main.cpp

    ../../../citadel-sample-game.cpp
)

add_library(citadel STATIC IMPORTED)
set_target_properties(citadel PROPERTIES IMPORTED_LOCATION ${citadel_DIR}/lib/android/${ANDROID_ABI}/libcitadel.a)

add_library(
    app-glue
    STATIC
    ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c
)

find_library(
    log-lib
    log
)

target_include_directories(citadel-sample PRIVATE ${citadel_DIR})

target_link_libraries(
    citadel-sample
    citadel
    app-glue

    -landroid
    -lEGL
    -lGLESv3

    ${log-lib}
)