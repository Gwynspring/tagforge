#pragma once

#include "config.hpp"
#include <filesystem>

Config load_config(const std::filesystem::path &config_path);
