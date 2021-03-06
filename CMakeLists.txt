cmake_minimum_required(VERSION 2.8)
project(lcio)

find_package(MPI REQUIRED)
add_definitions(-DOMPI_SKIP_MPICXX)
add_definitions(-D_FILE_OFFSET_BITS=64)

include_directories(.)
include_directories(${MPI_INCLUDE_PATH})
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Check functions

include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckTypeSize)

check_symbol_exists(posix_fallocate fcntl.h HAVE_POSIX_FALLOCATE)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h)


add_library(posix MODULE lib/posix.c)

add_library(mpiio MODULE lib/mpiio.c)

add_executable(lcio
        conf_parser.c
        conf_parser.h
        main.c
        lcio.h
        logging.h
        time.c
        params.c
        file_test.c
        lcio_math.c
        lcio_math.h
        exec_wrapper.c
        file_tree.c
        file_tree.h
        )

target_include_directories(lcio PRIVATE ${MPI_INCLUDE_PATH})
target_link_libraries(lcio PRIVATE ${MPI_LIBRARIES})
target_link_libraries(lcio PRIVATE m)
target_link_libraries(lcio PRIVATE dl)

target_link_libraries(mpiio PRIVATE ${MPI_LIBRARIES})
target_include_directories(mpiio PRIVATE ${MPI_INCLUDE_PATH})
