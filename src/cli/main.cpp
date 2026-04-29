#include "config.hpp"
#include "config_loader.hpp"
#include <filesystem>
#include <iostream>

int main() {

  std::filesystem::path file_path = "./examples/motor.yaml";
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
