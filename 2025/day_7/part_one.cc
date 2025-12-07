/**
 * Advent of Code 2025 - Day 7 - Part One
 * https://adventofcode.com/2025/day/7
 */

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

/**
 * @brief Finds the start point 'S' in the grid.
 * @param grid The grid of characters.
 * @return The column index of 'S', or -1 if not found.
 */
int FindStartColumn(const std::vector<std::string>& grid) {
  for (size_t c = 0; c < grid[0].size(); ++c) {
    if (grid[0][c] == 'S') {
      return c;
    }
  }
  return -1;
}

/**
 * @brief Simulates the flow through the grid and counts the number of splits.
 * @param grid The grid of characters.
 * @return The total number of splits encountered.
 */
int SimulateFlow(const std::vector<std::string>& grid) {
  int height = grid.size();
  int width = grid[0].size();
  int start_col = FindStartColumn(grid);

  std::set<int> current_active_cols;
  current_active_cols.insert(start_col);

  long long total_splits = 0;

  for (int r = 1; r < height; ++r) {
    std::set<int> next_active_cols;
    if (current_active_cols.empty()) break;

    for (int col : current_active_cols) {
      if (col < 0 || col >= width) continue;

      char c = grid[r][col];

      if (c == '^') {
        total_splits++;
        if (col - 1 >= 0) next_active_cols.insert(col - 1);
        if (col + 1 < width) next_active_cols.insert(col + 1);
      } else {
        next_active_cols.insert(col);
      }
    }
    current_active_cols = next_active_cols;
  }
  return total_splits;
}

int main(int argc, char* argv[]) {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }

  std::vector<std::string> grid;
  std::string line;
  while (std::getline(input, line)) {
    grid.push_back(line);
  }

  int total_splits = SimulateFlow(grid);
  std::cout << "Total splits encountered: " << total_splits << std::endl;

  return EXIT_SUCCESS;
}
