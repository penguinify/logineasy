cmake_minimum_required(VERSION 3.5.0)
# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(logineasy C)

add_executable(logineasy src/main.c)
