cmake_minimum_required(VERSION 3.10)

project(PUSHPUSH_BOMBBOMB)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -ansi -pedantic -O -Wconversion -std=c89 -Wno-implicit-fallthrough)
endif()

add_executable(PUSHPUSH_BOMBBOMB main.c bitwise.h bitwise.c dp_console.c dp_console.h drawHelper.c drawHelper.h struct.h)