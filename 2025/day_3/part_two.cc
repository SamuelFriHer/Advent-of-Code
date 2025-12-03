/**
 * Advent of Code 2025 - Day 3 - Part Two
 * https://adventofcode.com/2025/day/3
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief For every bank, finds the ordered combination of twelve digits that forms the greatest number.
 * @param banks A vector of vectors, where each inner vector represents a bank of digits.
 * @return A vector of vectors, where each inner vector contains the twelve digits that form the greatest number.
 */
std::vector<std::vector<char>> FindGreatestTwelveDigitCombinations(const std::vector<std::vector<char>>& banks) {
  std::vector<std::vector<char>> greatest_combinations;

  for (const auto& bank : banks) {
    std::vector<char> best_combination;
    int start_index = 0;

    for (int count = 0; count < 12; ++count) {
      char max_digit = '0';
      int max_index = start_index;
      for (size_t i = start_index; i <= bank.size() - (12 - count); ++i) {
        if (bank[i] > max_digit) {
          max_digit = bank[i];
          max_index = i;
        }
      }
      best_combination.push_back(max_digit);
      start_index = max_index + 1;
    }
    greatest_combinations.push_back(best_combination);
  }
  return greatest_combinations;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }
  std::vector<std::vector<char>> banks;
  std::string line;
  while (std::getline(input, line)) {
    std::vector<char> bank_row;
    for (char c : line) {
      bank_row.push_back(c);
    }
    banks.push_back(bank_row);
  }

  std::vector<std::vector<char>> greatest_combinations = FindGreatestTwelveDigitCombinations(banks);
  long long total_sum = 0;
  for (const auto& combination : greatest_combinations) {
    long long number = 0;
    for (char digit : combination) {
      number = number * 10 + (digit - '0');
    }
    total_sum += number;
  }
  std::cout << "Sum of greatest twelve-digit combinations: " << total_sum << std::endl;

  return EXIT_SUCCESS;
}