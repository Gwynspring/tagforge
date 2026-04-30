include(GoogleTest)
add_executable(test_generator test_generator.cpp)

target_link_libraries(
  test_generator
  tagforge_options
  config
  generator
  GTest::gtest_main
)

gtest_discover_tests(test_generator)
