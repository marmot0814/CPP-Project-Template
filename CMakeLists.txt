cmake_minimum_required (VERSION 3.14)

project(cpp-project-template VERSION 0.0.1)
enable_testing()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

# include Threads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# include openmp
find_package(OpenMP 4.5 REQUIRED)

# include submodules
add_subdirectory(submodules)

# executable
file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/submodules)

# link
target_link_libraries(${PROJECT_NAME} PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
# link more library ...
# target_link_libraries(${PROJECT_NAME} PRIVATE ...)

# setup compiler flag
target_compile_options(${PROJECT_NAME} PRIVATE -Ofast -Wall -Wextra -Wpedantic)

# unit-test
option(TEST "Build tests" ON)
if (TEST)
  add_subdirectory(tests)
endif()

# build document
option(DOC "Build documentation" OFF)
if (DOC)
  add_subdirectory(doc)
endif()
