/**
 * Advent of Code 2024 - Day 1 - Part One
 * https://adventofcode.com/2024/day/1
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }
  std::vector<int> left_numbers;
  std::vector<int> right_numbers;

  int left, right;
  while (input >> left >> right) {
    left_numbers.push_back(left);
    right_numbers.push_back(right);
  }
  input.close();

  std::sort(left_numbers.begin(), left_numbers.end());
  std::sort(right_numbers.begin(), right_numbers.end());

  int sum = 0;
  for (size_t i = 0; i < left_numbers.size(); ++i) {
    sum += abs(left_numbers[i] - right_numbers[i]);
  }
  std::cout << "The total distance is: " << sum << std::endl;
  return EXIT_SUCCESS;
}