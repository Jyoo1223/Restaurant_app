cmake_minimum_required(VERSION 3.10)
project(Restaurant)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers from include/ directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Build the restaurant library from Restaurant.cpp
add_library(restaurant src/Restaurant.cpp)

# Build the main executable and link with restaurant library
add_executable(main_exec src/main.cpp)
target_link_libraries(main_exec restaurant)

# Enable testing
enable_testing()
include(CTest)

if (WIN32)
    message(STATUS "Using manual Windows GoogleTest paths")

    set(GTEST_INCLUDE_DIR "C:/Software/Gtest/googletest-1.17.0/googletest/include")
    set(GTEST_LIB_DIR "C:/Software/Gtest/googletest-1.17.0/build/lib/Release")

    include_directories(${GTEST_INCLUDE_DIR})

    # List all test source files
    set(TEST_SOURCES
        tests/test_clearorder.cpp
        tests/test_emptyorder.cpp
        tests/test_ids.cpp
        tests/test_largequantity.cpp
        tests/test_menu.cpp
        tests/test_orderitem.cpp
        tests/test_setname.cpp
    )

    # Create test executables for each test source file
    foreach(test_src IN LISTS TEST_SOURCES)
        get_filename_component(test_name ${test_src} NAME_WE)
        add_executable(${test_name} ${test_src})
        target_link_libraries(${test_name} restaurant
            "${GTEST_LIB_DIR}/gtest.lib"
            "${GTEST_LIB_DIR}/gtest_main.lib"
        )
        add_test(NAME ${test_name} COMMAND ${test_name})
    endforeach()

else()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    set(TEST_SOURCES
        tests/test_clearorder.cpp
        tests/test_emptyorder.cpp
        tests/test_ids.cpp
        tests/test_largequantity.cpp
        tests/test_menu.cpp
        tests/test_orderitem.cpp
        tests/test_setname.cpp
    )

    foreach(test_src IN LISTS TEST_SOURCES)
        get_filename_component(test_name ${test_src} NAME_WE)
        add_executable(${test_name} ${test_src})
        target_link_libraries(${test_name} restaurant
            GTest::gtest
            GTest::gtest_main
            pthread
        )
        add_test(NAME ${test_name} COMMAND ${test_name})
    endforeach()
endif()
