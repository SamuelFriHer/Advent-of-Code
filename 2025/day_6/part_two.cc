/**
 * Advent of Code 2025 - Day 6 - Part Two
 * https://adventofcode.com/2025/day/6
 */

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Reads a vertical number from the matrix at the given column.
 * @param matrix The matrix of characters.
 * @param col The column index to read from.
 * @return The number formed by digits in the column.
 */
long long ReadVerticalNumber(const std::vector<std::string>& matrix, size_t col) {
  std::string num_str;
  // Iterate through all rows except the last one (which contains operators)
  for (size_t row = 0; row < matrix.size() - 1; ++row) {
    // Check bounds for the row string
    if (col < matrix[row].size() && std::isdigit(matrix[row][col])) {
      num_str += matrix[row][col];
    }
  }
  if (num_str.empty()) {
    return 0;
  }
  return std::stoll(num_str);
}

/**
 * @brief Calculates the total result based on the operators and vertical numbers.
 * @param matrix The input matrix containing numbers and the operator row.
 * @return The calculated total result.
 */
long long CalculateTotal(const std::vector<std::string>& matrix) {
  const std::string& operators_row = matrix.back();
  long long total_result = 0;

  // Find all indices of operators (non-space characters)
  std::vector<size_t> op_indices;
  for (size_t i = 0; i < operators_row.size(); ++i) {
    if (operators_row[i] != ' ') {
      op_indices.push_back(i);
    }
  }

  // Add a sentinel index for easier segment processing
  op_indices.push_back(operators_row.size() + 1);

  for (size_t i = 0; i < op_indices.size() - 1; ++i) {
    size_t segment_start = op_indices[i];
    size_t segment_end = op_indices[i + 1];

    char op = operators_row[segment_start];
    long long current_op_result = ReadVerticalNumber(matrix, segment_start);

    // Iterate through columns between the operators
    for (size_t col = segment_start + 1; col + 1 < segment_end; ++col) {
      long long number = ReadVerticalNumber(matrix, col);
      if (op == '+') {
        current_op_result += number;
      } else if (op == '*') {
        current_op_result *= number;
      }
    }
    total_result += current_op_result;
  }

  return total_result;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return 1;
  }

  std::vector<std::string> matrix;
  std::string line;
  while (std::getline(input, line)) {
    matrix.push_back(line);
  }

  long long result = CalculateTotal(matrix);
  std::cout << "Total sum of column operations: " << result << std::endl;

  return 0;
}
