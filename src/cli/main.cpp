#include "config.hpp"
#include "config_loader.hpp"
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
    std::cout << "File successfully loaded\r\n";
    std::cout << "Type: " << cfg.type_name << "\r\n";
    std::cout << "Prefix : " << cfg.prefix << "\r\n";
    std::cout << "Count : " << cfg.count << "\r\n";

    for (const auto &it : cfg.variables) {
      std::cout << it.name << "\r\n";
      std::cout << it.comment << "\r\n";
    }
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
