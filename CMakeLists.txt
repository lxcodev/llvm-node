cmake_minimum_required(VERSION 3.6)
project(llvm-node)

set(CMAKE_CXX_STANDARD 14)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using llvm include dirs in: ${LLVM_INCLUDE_DIRS}")
message(STATUS "c++ version in: ${CMAKE_CXX_COMPILER}")

include_directories(${CMAKE_JS_INC} "./node_modules/nan" ${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS} -DNOMINMAX)

file(GLOB SOURCE_FILES 
        "src/*.h"
        "src/*.cc"
        "src/**/*.h"
        "src/**/*.cc"
        )


add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")


llvm_map_components_to_libnames(llvm_libs ${LLVM_TARGETS_TO_BUILD} core orcjit native runtimedyld)

# Link against LLVM libraries
target_link_libraries(${PROJECT_NAME} ${llvm_libs} ${CMAKE_JS_LIB} -lm -lz -lcurses )