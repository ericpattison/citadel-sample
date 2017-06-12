cmake_minimum_required(VERSION 3.4.1)

include_directories(
    ../../../citadel
    ${ANDROID_NDK}/sources/android/native_app_glue
)

add_library(
    citadel-sample
    SHARED
    #src/main/cpp/main.cpp

    ../../../citadel-sample-game.cpp
)

add_library(
    app-glue
    STATIC
    ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c
)


find_library(
    log-lib
    log
)

target_link_libraries(
    citadel-sample
    app-glue

    -landroid

    ${log-lib}
)