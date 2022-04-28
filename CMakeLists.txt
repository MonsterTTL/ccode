cmake_minimum_required(VERSION 3.21)
project(cODE C)

set(CMAKE_C_STANDARD 11)

include_directories(prinmerC)

add_executable(cODE
        EPI/datReading.c
        EPI/filem.c
        EPI/shenfenzheng.c
        "EPI/string rangge.c"
        EPI/tayor.c
        EPI/tempCodeRunnerFile.c
        EPI/test1.c
        libr/lib.c
        nwe/datReading.c
        prinmerC/angle.c
        prinmerC/angle.h
        prinmerC/rect.c
        prinmerC/test.c
        prinmerC/δ����2.c
        tmp/rect.c
        tmp/test.c
        trash/main.c
        trash/rangge.c)
