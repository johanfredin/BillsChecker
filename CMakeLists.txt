cmake_minimum_required(VERSION 3.4)
project(BillsChecker)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(SOURCE_FILES main.c source-files/bill.c)
add_executable(BillsChecker ${SOURCE_FILES})