/**
 * Advent of Code 2024 - Day 2 - Part One
 * https://adventofcode.com/2024/day/2
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/**
 * @brief Checks if the elements of the vector are in ascending or descending order.
 * @param numbers A vector of integers to check.
 * @return true if the numbers are in ascending or descending order, false otherwise.
 */
bool isOrdered(const std::vector<int>& numbers) {
  bool ascending = true;
  bool descending = true;

  for (size_t i = 1; i < numbers.size(); ++i) {
    if (numbers[i] > numbers[i - 1]) {
      descending = false;
    } else if (numbers[i] < numbers[i - 1]) {
      ascending = false;
    }
  }
  return ascending || descending;
}

/**
 * @brief Checks if all adjacent elements in the vector differ by at least one and at most three.
 * @param numbers A vector of integers to check.
 * @return true if all adjacent elements differ by 1 to 3, false otherwise.
 */
bool hasValidDifferences(const std::vector<int>& numbers) {
  for (size_t i = 1; i < numbers.size(); ++i) {
    int diff = std::abs(numbers[i] - numbers[i - 1]);
    if (diff < 1 || diff > 3) {
      return false;
    }
  }
  return true;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }

  int sum = 0;
  std::vector<int> numbers;
  std::string line;
  while (std::getline(input, line)) {
    std::istringstream iss(line);
    int number;
    while (iss >> number) {
      numbers.push_back(number);
    }
    if (isOrdered(numbers) && hasValidDifferences(numbers)) {
      sum += 1;
    }
    numbers.clear();
  }
  std::cout << sum << " reports are safe." << std::endl;
  return EXIT_SUCCESS;
}