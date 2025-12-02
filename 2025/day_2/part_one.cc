/**
 * Advent of Code 2025 - Day 2 - Part One
 * https://adventofcode.com/2025/day/2
 */

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Finds, within the the given ranges, all the numbers
 *        in which the first half is exactly the same as the second half.
 * @param ranges A vector of pairs representing the ranges (start, end).
 * @return A vector of longegers that meet the criteria.
 */
std::vector<long> FindSymmetricNumbers(const std::vector<std::pair<long, long>>& ranges) {
  std::vector<long> symmetric_numbers;

  for (const auto& [start, end] : ranges) {
    for (long number = start; number <= end; ++number) {
      std::string num_str = std::to_string(number);
      size_t len = num_str.length();
      if (len % 2 != 0) {
        continue;  // Skip numbers with odd length
      }
      std::string first_half = num_str.substr(0, len / 2);
      std::string second_half = num_str.substr(len / 2, len / 2);
      if (first_half == second_half) {
        symmetric_numbers.push_back(number);
      }
    }
  }
  return symmetric_numbers;
}

/**
 * @brief Given an input line, returns all the ranges as pairs of longegers.
 * @param line A string representing ranges in the format "a-b,c-d,..."
 * @return A vector of pairs, where each pair represents a range (start, end).
 */
std::vector<std::pair<long, long>> ParseRanges(const std::string& line) {
  std::vector<std::pair<long, long>> ranges;
  size_t start = 0;
  size_t end = line.find(',');

  while (end != std::string::npos) {
    std::string range_str = line.substr(start, end - start);
    size_t dash_pos = range_str.find('-');
    long range_start = std::stol(range_str.substr(0, dash_pos));
    long range_end = std::stol(range_str.substr(dash_pos + 1));
    ranges.emplace_back(range_start, range_end);
    start = end + 1;
    end = line.find(',', start);
  }
  // Add the last range after the final comma
  std::string range_str = line.substr(start);
  size_t dash_pos = range_str.find('-');
  long range_start = std::stol(range_str.substr(0, dash_pos));
  long range_end = std::stol(range_str.substr(dash_pos + 1));
  ranges.emplace_back(range_start, range_end);

  return ranges;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }
  std::vector<std::pair<long, long>> ranges;
  std::string line;
  while (std::getline(input, line)) {
    std::vector<std::pair<long, long>> parsed_ranges = ParseRanges(line);
    ranges.insert(ranges.end(), parsed_ranges.begin(), parsed_ranges.end());
  }
  std::vector<long> symmetric_numbers = FindSymmetricNumbers(ranges);

  long total_sum = 0;
  for (long number : symmetric_numbers) {
    total_sum += number;
  }
  std::cout << "Total sum of symmetric numbers: " << total_sum << std::endl;

  return EXIT_SUCCESS;
}