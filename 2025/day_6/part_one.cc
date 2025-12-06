/**
 * Advent of Code 2025 - Day 6 - Part One
 * https://adventofcode.com/2025/day/6
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief Calculate the result of adding the results of every column operation.
 * @param columns A vector of vectors, where each column contains integers to operate on.
 * @param operators A vector of characters representing the operation for each column.
 * @return The total sum of the results from each column operation.
 */
long CalculateColumnOperations(const std::vector<std::vector<int>>& columns, const std::vector<char>& operators) {
  long total_sum = 0;

  for (size_t i = 0; i < columns[0].size(); ++i) {
    long column_result = 0;
    for (size_t j = 0; j < columns.size(); ++j) {
      if (operators[i] == '+') {
        column_result += columns[j][i];
      } else if (operators[i] == '*') {
        if (j == 0) {
          column_result = columns[j][i];
        } else {
          column_result *= columns[j][i];
        }
      }
    }
    total_sum += column_result;
  }
  return total_sum;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }

  std::vector<std::vector<int>> columns;
  std::string line;
  for (int i = 0; i < 4; ++i) {
    std::getline(input, line);
    std::istringstream ss(line);
    std::vector<int> row;

    int value;
    while (ss >> value) {
      row.push_back(value);
    }
    columns.push_back(row);
  }

  std::vector<char> operators;
  std::getline(input, line);
  std::istringstream op_ss(line);
  char op;
  while (op_ss >> op) {
    operators.push_back(op);
  }

  long result = CalculateColumnOperations(columns, operators);
  std::cout << "Total sum of column operations: " << result << std::endl;

  return EXIT_SUCCESS;
}