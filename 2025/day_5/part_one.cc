/**
 * Advent of Code 2025 - Day 5 - Part One
 * https://adventofcode.com/2025/day/5
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Merge overlapping or contiguous ranges.
 * @param ranges A vector of pairs representing the ranges to be merged.
 * @return A vector of merged ranges.
 */
std::vector<std::pair<long, long>> MergeRanges(const std::vector<std::pair<long, long>>& ranges) {
  std::vector<std::pair<long, long>> sorted_ranges = ranges;
  std::sort(sorted_ranges.begin(), sorted_ranges.end());
  std::vector<std::pair<long, long>> merged;

  for (const auto& range : sorted_ranges) {
    if (merged.empty() || merged.back().second < range.first - 1) {
      merged.push_back(range);
    } else {
      merged.back().second = std::max(merged.back().second, range.second);
    }
  }
  return merged;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }

  // Read the input lines containing two numbers separated by a dash until an empty line is encountered
  std::vector<std::pair<long, long>> ranges;
  std::string line;
  while (std::getline(input, line) && !line.empty()) {
    size_t dash_pos = line.find('-');
    if (dash_pos != std::string::npos) {
      long start = std::stol(line.substr(0, dash_pos));
      long end = std::stol(line.substr(dash_pos + 1));
      ranges.emplace_back(start, end);
    }
  }

  std::vector<std::pair<long, long>> merged = MergeRanges(ranges);

  int count = 0;
  // Read the remaining lines containing single numbers
  while (std::getline(input, line) && !line.empty()) {
    long number = std::stol(line);
    for (const auto& range : merged) {
      if (number >= range.first && number <= range.second) {
        count++;
        break;
      }
    }
  }

  std::cout << "Count of numbers within ranges: " << count << std::endl;

  return EXIT_SUCCESS;
}