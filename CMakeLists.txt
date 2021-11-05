# cmake_minimum_required(VERSION 3.16)

# project("RISC-V")

# set(EXEC_FILE "exec")

# set(HEADERS common.h
#     implement/physmemory.h
#     implement/implement.h
#     parser/parser.h )

# set(SOURCES main.c errors.c
#     implement/implement.c
#     parser/parser.c )

# #compiler settings
# add_compile_options (
#     -Wall
#     -Wextra )

# #executable files
# add_executable(${EXEC_FILE} ${SOURCES})

cmake_minimum_required( VERSION 3.16)

project (RISC-V-interpreter VERSION 1.0.0)               # PROJECT TITLE

include(CMakePrintHelpers)

set( EXEC_NAME "interpreter" )
add_executable( ${EXEC_NAME} )

target_include_directories( ${EXEC_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/headers"
)



set( EXECSOURCES "${CMAKE_SOURCE_DIR}/sources" )

set( SOURCES
    "errors.c"
    "implement.c"
    "parser.c"
    "main.c"
  )


# set (COMPILER_SETTINGS -Wall -Wextra -O2)       # COMPILER SETTINGS

target_sources( ${EXEC_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/sources/main.c" )

foreach( FILE IN LISTS SOURCES)
    target_sources( ${EXEC_NAME} PRIVATE "${EXECSOURCES}/${FILE}" )
endforeach()

    if ( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        set (COMPILER_SETTINGS -Wall -Wextra -O0 -g -D DEBUG)
        
    else ()
        set (COMPILER_SETTINGS -Wall -Wextra -O2 -Wfloat-equal -Wdiv-by-zero)
        cmake_print_variables(CMAKE_BUILD_TYPE)

    endif ()

target_compile_options( ${EXEC_NAME} PRIVATE ${COMPILER_SETTINGS} )

# target_compile_options( ${EXEC_NAME} PRIVATE ${COMPILER_SETTINGS})