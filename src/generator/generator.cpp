#include "generator.hpp"
#include <format>

static std::string scl_type_to_string(const SclType &type) {
  switch (type) {
  case SclType::Bool:
    return "BOOL";
  case SclType::Int:
    return "INT";
  case SclType::Real:
    return "REAL";
  case SclType::Word:
    return "WORD";
  case SclType::DWord:
    return "DWORD";
  default:
    return "Unknown";
  }
}

static std::string format_variable_name(const std::string &pre, int cnt,
                                        int idx, const std::string &name) {
  if (cnt == 1) {
    return pre + "_" + name;
  }

  return pre + "_" + std::to_string(idx) + "_" + name;
}

std::string Generator::generate(const Config &cfg) {
  std::string output = std::format("TYPE {}\r\nVERSION : {}\r\n\tSTRUCT\r\n",
                                   cfg.type_name, 0.1);

  for (size_t i = 0; i < cfg.count; i++) {
    for (const auto &it : cfg.variables) {
      output +=
          "\t\t" + format_variable_name(cfg.prefix, cfg.count, i + 1, it.name) +
          " : " + scl_type_to_string(it.type) + "\t\t" + it.comment + "\r\n";
    }
  }

  output += std::format("\tEND_STRUCT;\r\nEND_TYPE;");
  return output;
}
