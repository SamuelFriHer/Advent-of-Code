/**
 * Advent of Code 2025 - Day 3 - Part One
 * https://adventofcode.com/2025/day/3
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief For every bank, finds the ordered pair of digits that forms the greatest number.
 * @param banks A vector of vectors, where each inner vector represents a bank of digits.
 * @return A vector of pairs, where each pair contains the two digits that form the greatest number.
 */
std::vector<std::pair<char, char>> FindGreatestDigitPairs(const std::vector<std::vector<char>>& banks) {
  std::vector<std::pair<char, char>> greatest_pairs;

  for (const auto& bank : banks) {
    int max_num = -1;
    std::pair<char, char> best_pair;
    for (size_t i = 0; i < bank.size() - 1; ++i) {
      for (size_t j = i + 1; j < bank.size(); ++j) {
        int current_num = (bank[i] - '0') * 10 + (bank[j] - '0');
        if (current_num > max_num) {
          max_num = current_num;
          best_pair = {bank[i], bank[j]};
        }
      }
    }
    greatest_pairs.push_back(best_pair);
  }
  return greatest_pairs;
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

  std::vector<std::pair<char, char>> greatest_pairs = FindGreatestDigitPairs(banks);
  int sum = 0;
  for (const auto& p : greatest_pairs) {
    sum += (p.first - '0') * 10 + (p.second - '0');
  }
  std::cout << "Sum of greatest digit pairs: " << sum << std::endl;

  return EXIT_SUCCESS;
}