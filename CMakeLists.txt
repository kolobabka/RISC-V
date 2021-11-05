cmake_minimum_required(VERSION 3.16)

project("RISC-V")

set(EXEC_FILE "exec")

set(HEADERS common.h
    implement/physmemory.h
    implement/implement.h
    parser/parser.h )

set(SOURCES main.c errors.c
    implement/implement.c
    parser/parser.c )

#compiler settings
add_compile_options (
    -Wall
    -Wextra )

#executable files
add_executable(${EXEC_FILE} ${SOURCES})
