# Tests
add_executable(test_gen test_gen.cc)
add_executable(test_expiration test_expiration.cc)
add_test(TestGen test_gen)
add_test(TestExpiration test_expiration)

# Use PkgConfig
include(FindPkgConfig)
find_package(PkgConfig REQUIRED)
pkg_search_module(GTEST REQUIRED gtest)

# Add and linking libraries for Executable
target_link_libraries(test_gen PUBLIC ${GTEST_LIBRARIES} ${PROJECT_NAME})
target_link_libraries(test_expiration PUBLIC ${GTEST_LIBRARIES} ${PROJECT_NAME})