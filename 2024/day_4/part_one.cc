/**
 * Advent of Code 2024 - Day 4 - Part One
 * https://adventofcode.com/2024/day/4
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::vector<char>> Grid;

/**
 * @brief Counts all the horizontal appearances of the word "XMAS" in the grid, forwards and backwards.
 * @param grid The 2D grid of characters.
 * @return The count of horizontal "XMAS" appearances.
 */
int CountHorizontalXMAS(const Grid& grid) {
  int count = 0;
  const std::string target = "XMAS";

  for (const auto& row : grid) {
    std::string row_str(row.begin(), row.end());
    // Check forwards
    for (size_t i = 0; i <= row_str.size() - target.size(); ++i) {
      if (row_str.substr(i, target.size()) == target) {
        count++;
      }
    }
    // Check backwards
    std::string reversed_row_str(row_str.rbegin(), row_str.rend());
    for (size_t i = 0; i <= reversed_row_str.size() - target.size(); ++i) {
      if (reversed_row_str.substr(i, target.size()) == target) {
        count++;
      }
    }
  }
  return count;
}

/**
 * @brief Counts all the vertical appearances of the word "XMAS" in the grid, forwards and backwards.
 * @param grid The 2D grid of characters.
 * @return The count of vertical "XMAS" appearances.
 */
int CountVerticalXMAS(const Grid& grid) {
  int count = 0;
  const std::string target = "XMAS";
  size_t rows = grid.size();
  if (rows == 0) return 0;
  size_t cols = grid[0].size();

  for (size_t col = 0; col < cols; ++col) {
    std::string col_str;
    for (size_t row = 0; row < rows; ++row) {
      col_str += grid[row][col];
    }
    // Check forwards
    for (size_t i = 0; i <= col_str.size() - target.size(); ++i) {
      if (col_str.substr(i, target.size()) == target) {
        count++;
      }
    }
    // Check backwards
    std::string reversed_col_str(col_str.rbegin(), col_str.rend());
    for (size_t i = 0; i <= reversed_col_str.size() - target.size(); ++i) {
      if (reversed_col_str.substr(i, target.size()) == target) {
        count++;
      }
    }
  }
  return count;
}

/**
 * @brief Counts all the diagonal appearances of the word "XMAS" in the grid, in all four diagonal directions.
 * @param grid The 2D grid of characters.
 * @return The count of diagonal "XMAS" appearances.
 */
int CountDiagonalXMAS(const Grid& grid) {
  int count = 0;
  const std::string target = "XMAS";
  size_t rows = grid.size();
  if (rows == 0) return 0;
  size_t cols = grid[0].size();

  // Check diagonals from top-left to bottom-right
  for (size_t r = 0; r <= rows - target.size(); ++r) {
    for (size_t c = 0; c <= cols - target.size(); ++c) {
      std::string diag_str;
      for (size_t i = 0; i < target.size(); ++i) {
        diag_str += grid[r + i][c + i];
      }
      if (diag_str == target) count++;
      std::string reversed_diag_str(diag_str.rbegin(), diag_str.rend());
      if (reversed_diag_str == target) count++;
    }
  }

  // Check diagonals from top-right to bottom-left
  for (size_t r = 0; r <= rows - target.size(); ++r) {
    for (size_t c = target.size() - 1; c < cols; ++c) {
      std::string diag_str;
      for (size_t i = 0; i < target.size(); ++i) {
        diag_str += grid[r + i][c - i];
      }
      if (diag_str == target) count++;
      std::string reversed_diag_str(diag_str.rbegin(), diag_str.rend());
      if (reversed_diag_str == target) count++;
    }
  }

  return count;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }

  Grid grid;
  std::string line;
  while (std::getline(input, line)) {
    std::vector<char> row(line.begin(), line.end());
    grid.push_back(row);
  }
  input.close();

  int horizontal_count = CountHorizontalXMAS(grid);
  int vertical_count = CountVerticalXMAS(grid);
  int diagonal_count = CountDiagonalXMAS(grid);
  int total_count = horizontal_count + vertical_count + diagonal_count;

  std::cout << "'XMAS' appears " << total_count << " times in the grid." << std::endl;
  return EXIT_SUCCESS;
}