#include "config.hpp"
#include "config_loader.hpp"
#include "generator.hpp"
#include <filesystem>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "tagforge: missing input file!\n";
    return EXIT_FAILURE;
  }
  std::filesystem::path file_path = argv[1];
  try {
    Config cfg = load_config(file_path);
    std::string output = Generator::generate(cfg);
    std::cout << output;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
