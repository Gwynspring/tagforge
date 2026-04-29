#include "config_loader.hpp"
#include <unordered_map>
#include <yaml-cpp/yaml.h>

static SclType parse_scl_type(const std::string &s) {
  static const std::unordered_map<std::string, SclType> type_map = {
      {"Bool", SclType::Bool},   {"Int", SclType::Int},
      {"Real", SclType::Real},   {"Word", SclType::Word},
      {"DWord", SclType::DWord},
  };

  auto it = type_map.find(s);
  if (it == type_map.end()) {
    throw std::runtime_error("Unknown Scl type " + s);
  }
  return it->second;
}

Config load_config(const std::filesystem::path &config_path) {
  YAML::Node node = YAML::LoadFile(config_path.string());
  if (!node["type_name"] || node["type_name"].IsNull()) {
    throw std::runtime_error("Missing required field: type_name");
  }

  if (!node["variables"]) {
    throw std::runtime_error("Missing required field: variables");
  }

  Config cfg;
  cfg.type_name = node["type_name"].as<std::string>();
  if (node["prefix"]) {
    cfg.prefix = node["prefix"].as<std::string>();
  }

  if (node["count"]) {
    int count = node["count"].as<int>();
    if (count < 1) {
      throw std::runtime_error("count must be at least 1");
    }

    if (count > 0xFFFF) {
      throw std::runtime_error("count must not exceed 65535");
    }

    cfg.count = static_cast<uint16_t>(count);
  }

  for (const auto &item : node["variables"]) {
    if (!item["name"]) {
      throw std::runtime_error("Missing required field: variable name");
    }
    std::string name = item["name"].as<std::string>();
    std::string type = item["type"].as<std::string>();
    std::string comment = item["comment"].as<std::string>("");

    Variable v{.name = name, .type = parse_scl_type(type), .comment = comment};
    cfg.variables.push_back(v);
  }

  return cfg;
}
