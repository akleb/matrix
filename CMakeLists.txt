cmake_minimum_required(VERSION 3.10)

project(Matrix VERSION 1.0.0)

enable_language(C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(MatrixDirs)

IF (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
     "Build types are: None Debug Release RelWithDebInfo."
     FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

include_directories(${INCDIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

set(M_INC ${INCDIR}/matrix.h)
set(M_SRC ${SRCDIR}/matrix.c)

# Add compiling to flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCOMPILING=yes")

# ----------------
#  Library Target
# ----------------
add_library(Matrix ${M_SRC} ${M_INC})

# --------------
#  Unit Testing
# --------------
enable_testing()
include(add_unit_test)
add_subdirectory(tests)
