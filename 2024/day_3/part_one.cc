/**
 * Advent of Code 2024 - Day 3 - Part One
 * https://adventofcode.com/2024/day/3
 */

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Extracts from a string all the sequences matching /mul\(\d+,\d+\)/
 * @param line The input string to search within.
 * @return A vector of pairs of integers representing the extracted multiplication operations.
 */
std::vector<std::pair<int, int>> extractMultiplications(const std::string& line) {
  std::vector<std::pair<int, int>> multiplications;

  std::regex mul_regex(R"(mul\((\d+),(\d+)\))");
  auto words_begin = std::sregex_iterator(line.begin(), line.end(), mul_regex);
  auto words_end = std::sregex_iterator();

  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    multiplications.push_back({std::stoi((*i)[1].str()), std::stoi((*i)[2].str())});
  }
  return multiplications;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }

  std::string line;
  std::vector<std::pair<int, int>> all_multiplications;
  while (std::getline(input, line)) {
    auto multiplications = extractMultiplications(line);
    all_multiplications.insert(all_multiplications.end(), multiplications.begin(), multiplications.end());
  }
  input.close();

  int total_sum = 0;
  for (const auto& mul : all_multiplications) {
    total_sum += mul.first * mul.second;
  }
  std::cout << "If you add up all of the results of the multiplications, you get: " << total_sum << std::endl;
}