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

set(M_INC ${INCDIR}/matrix)
set(M_SRC ${SRCDIR}/matrix)

# Add compiling to flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCOMPILING=yes")

#functions we have
set(Matrix_init TRUE)

foreach(TYPE int float double)
    set(HEADER_INCLUDE "#include \"matrix_${TYPE}.h\"")
    configure_file(${M_SRC}.c ${M_SRC}_${TYPE}.c)
    configure_file(${M_INC}.h ${M_INC}_${TYPE}.h)
    add_library(${TYPE}Matrix ${M_SRC}_${TYPE}.c ${M_INC}_${TYPE}.h)
endforeach()

# ----------------
#  Library Target
# ----------------

# --------------
#  Unit Testing
# --------------
enable_testing()
include(add_unit_test)
add_subdirectory(tests)
