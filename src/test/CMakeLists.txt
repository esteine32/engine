# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()


# Now simply link against gtest or gtest_main as needed
add_executable(Point2Test Point2Test.cpp)
target_link_libraries(Point2Test gtest_main)
add_test(NAME Point2Test COMMAND Point2Test)

add_executable(Point3Test Point3Test.cpp)
target_link_libraries(Point3Test gtest_main)
add_test(NAME Point3Test COMMAND Point3Test)

add_executable(Vector2Test Vector2Test.cpp)
target_link_libraries(Vector2Test gtest_main)
add_test(NAME Vector2Test COMMAND Vector2Test)

add_executable(Vector3Test Vector3Test.cpp)
target_link_libraries(Vector3Test gtest_main)
add_test(NAME Vector3Test COMMAND Vector3Test)

add_executable(Line2Test Line2Test.cpp)
target_link_libraries(Line2Test gtest_main)
add_test(NAME Line2Test COMMAND Line2Test)

add_executable(Line3Test Line3Test.cpp)
target_link_libraries(Line3Test gtest_main)
add_test(NAME Line3Test COMMAND Line3Test)

add_executable(PlaneTest PlaneTest.cpp)
target_link_libraries(PlaneTest gtest_main)
add_test(NAME PlaneTest COMMAND PlaneTest)
