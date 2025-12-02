/**
 * Advent of Code 2025 - Day 2 - Part Two
 * https://adventofcode.com/2025/day/2
 */

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Finds, within the the given ranges, all the numbers
 *        in which a patern is repeated at least twice consecutively using all digits.
 * @param ranges A vector of pairs representing the ranges (start, end).
 * @return A vector of longegers that meet the criteria.
 */
std::vector<long> FindPatternRepeatedNumbers(const std::vector<std::pair<long, long>>& ranges) {
  std::vector<long> pattern_repeated_numbers;

  for (const auto& [start, end] : ranges) {
    for (long number = start; number <= end; ++number) {
      std::string num_str = std::to_string(number);
      size_t len = num_str.length();
      bool found_pattern = false;

      for (size_t pattern_len = 1; pattern_len <= len / 2; ++pattern_len) {
        if (len % pattern_len != 0) {
          continue;  // The pattern length must divide the total length
        }
        std::string pattern = num_str.substr(0, pattern_len);
        std::string repeated_pattern;
        for (size_t i = 0; i < len / pattern_len; ++i) {
          repeated_pattern += pattern;
        }
        if (repeated_pattern == num_str) {
          pattern_repeated_numbers.push_back(number);
          found_pattern = true;
          break;  // No need to check further patterns
        }
      }
    }
  }
  return pattern_repeated_numbers;
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
  std::vector<long> pattern_repeated_numbers = FindPatternRepeatedNumbers(ranges);

  long total_sum = 0;
  for (long number : pattern_repeated_numbers) {
    total_sum += number;
  }
  std::cout << "Total sum of pattern repeated numbers: " << total_sum << std::endl;

  return EXIT_SUCCESS;
}