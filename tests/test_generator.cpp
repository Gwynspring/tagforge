#include "config.hpp"
#include "generator.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(BasicGenerator, GeneratorBaseCase) {
  std::vector<Variable> vars = {

      Variable{"speed", SclType::Int, "Test Motor 1"},
      {Variable{"is_running", SclType::Bool, "Test Motor 1 is_running"}}};

  Config cfg = {.type_name = "Motor_variables",
                .prefix = "Motor",
                .count = 1,
                .variables = vars};

  std::string output = Generator::generate(cfg);

  std::string test_output =
      "TYPE Motor_variables\r\nVERSION : 0.1\r\n\tSTRUCT\r\n";
  test_output += "\t\tMotor_speed : INT\t\tTest Motor 1\r\n";
  test_output += "\t\tMotor_is_running : BOOL\t\tTest Motor 1 is_running\r\n";
  test_output += "\tEND_STRUCT;\r\nEND_TYPE;";

  EXPECT_EQ(output, test_output);
}
