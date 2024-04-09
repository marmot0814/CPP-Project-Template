set(TARGET_NAME ${PROJECT_NAME}-test)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/tests/*.cpp)

add_executable(${TARGET_NAME} ${SOURCE_FILES})

option (GCOV "Build with gcov" OFF)
if (GCOV)
  include(CodeCoverage)
  append_coverage_compiler_flags()
  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE ${CMAKE_BINARY_DIR}/tests/${TARGET_NAME}
    BASE_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
    DEPENDENCIES ${TARGET_NAME}
    EXCLUDE "/usr/include/*"
            "${PROJECT_SOURCE_DIR}/tests/*"
            "${PROJECT_SOURCE_DIR}/submodules/*"
  )
endif()

target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/submodules)
target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/tests)

target_compile_definitions(${TARGET_NAME}
  PRIVATE DATA_PATH="${PROJECT_SOURCE_DIR}/tests/data")

add_test(${TARGET_NAME} ${CMAKE_BINARY_DIR}/tests/${TARGET_NAME})
