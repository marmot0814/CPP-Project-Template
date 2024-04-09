#include "catch.hpp"

#include <example.hpp>
#include <filesystem>
#include <fstream>

// Test case for the ExampleClass
TEST_CASE("ExampleClass Test", "[ExampleClass]") {
  ExampleClass example;

  SECTION("Function Test") {
    // Call the function being tested
    int result = example.function();

    // Load data from DATA_PATH
    auto data_path = std::filesystem::path{DATA_PATH};
    auto fin = std::ifstream{data_path / "file.txt"};
    int answer;
    fin >> answer;

    // Check if the result is as expected
    REQUIRE(result == answer);
  }
}
