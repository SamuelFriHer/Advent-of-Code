/**
 * Advent of Code 2025 - Day 4 - Part One
 * https://adventofcode.com/2025/day/4
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Counts all the '@' that have fewer than four '@' in the eight adjacent positions.
 * @param grid A vector of vectors, where each inner vector represents a row of characters in the grid.
 * @return The count of '@' characters that meet the criteria.
 */
int CountIsolatedAtSymbols(const std::vector<std::vector<char>>& grid) {
  int count = 0;
  int rows = grid.size();
  int cols = grid[0].size();

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (grid[i][j] == '@') {
        int adjacent_count = 0;
        for (int di = -1; di <= 1; ++di) {
          for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0) continue;  // Skip the current position
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == '@') {
              adjacent_count++;
            }
          }
        }
        if (adjacent_count < 4) {
          count++;
        }
      }
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
  std::vector<std::vector<char>> grid;
  std::string line;
  while (std::getline(input, line)) {
    std::vector<char> row;
    for (char c : line) {
      row.push_back(c);
    }
    grid.push_back(row);
  }
  input.close();

  int isolated_count = CountIsolatedAtSymbols(grid);
  std::cout << "Count of isolated '@' symbols: " << isolated_count << std::endl;

  return EXIT_SUCCESS;
}