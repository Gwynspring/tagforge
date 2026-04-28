#pragma once

#include <cstdint>
#include <string>
#include <vector>

enum class SclType { Unknown, Bool, Int, Real, Word, DWord };

struct Variable {
  std::string name;
  SclType type = SclType::Unknown;
  std::string comment;
};

struct Config {
  std::string type_name;
  std::string prefix;
  uint16_t count = 1;
  std::vector<Variable> variables;
};
