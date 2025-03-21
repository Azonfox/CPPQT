cmake_minimum_required(VERSION 3.5)

project(aaa LANGUAGES C)

add_executable(aaa main.c)

install(TARGETS aaa
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
