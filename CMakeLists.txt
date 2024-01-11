cmake_minimum_required(VERSION 3.26)
project(PRJ)

set(CMAKE_CXX_STANDARD 17)

add_executable(PRJ main.cpp
        FlowStep.cpp
        FlowStep.h
        Flow.cpp
        Flow.h
        FSManager.cpp
        FSManager.h
        FlowFactory.cpp
        FlowFactory.h)
