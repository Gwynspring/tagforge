add_library(config STATIC config_loader.cpp)

target_include_directories(config PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(config PRIVATE
  tagforge_options
  yaml-cpp::yaml-cpp
)
