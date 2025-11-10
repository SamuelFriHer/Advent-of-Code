/**
 * Advent of Code 2024 - Day 4 - Part Two
 * https://adventofcode.com/2024/day/4
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::vector<char>> Grid;

/**
 * @brief Counts all the appearances of the following pattern:
 *  M S
 *   A
 *  M S
 * @param grid The grid to search within.
 * @return The count of pattern appearances.
 */
int CountLeftPatternAppearances(const Grid& grid) {
  int count = 0;
  int rows = grid.size();
  if (rows == 0) return 0;
  int cols = grid[0].size();

  for (int r = 0; r < rows - 2; ++r) {
    for (int c = 0; c < cols - 2; ++c) {
      if (grid[r][c] == 'M' && grid[r][c + 2] == 'S' && grid[r + 1][c + 1] == 'A' && grid[r + 2][c] == 'M' &&
          grid[r + 2][c + 2] == 'S') {
        count++;
      }
    }
  }
  return count;
}

/**
 * @brief Counts all the appearances of the following pattern:
 *  M M
 *   A
 *  S S
 * @param grid The grid to search within.
 * @return The count of pattern appearances.
 */
int CountUpperPatternAppearances(const Grid& grid) {
  int count = 0;
  int rows = grid.size();
  if (rows == 0) return 0;
  int cols = grid[0].size();

  for (int r = 0; r < rows - 2; ++r) {
    for (int c = 0; c < cols - 2; ++c) {
      if (grid[r][c] == 'M' && grid[r][c + 2] == 'M' && grid[r + 1][c + 1] == 'A' && grid[r + 2][c] == 'S' &&
          grid[r + 2][c + 2] == 'S') {
        count++;
      }
    }
  }
  return count;
}

/**
 * @brief Counts all the appearances of the following pattern:
 *  S M
 *   A
 *  S M
 * @param grid The grid to search within.
 * @return The count of pattern appearances.
 */
int CountRightPatternAppearances(const Grid& grid) {
  int count = 0;
  int rows = grid.size();
  if (rows == 0) return 0;
  int cols = grid[0].size();

  for (int r = 0; r < rows - 2; ++r) {
    for (int c = 0; c < cols - 2; ++c) {
      if (grid[r][c] == 'S' && grid[r][c + 2] == 'M' && grid[r + 1][c + 1] == 'A' && grid[r + 2][c] == 'S' &&
          grid[r + 2][c + 2] == 'M') {
        count++;
      }
    }
  }
  return count;
}

/**
 * @brief Counts all the appearances of the following pattern:
 *  S S
 *   A
 *  M M
 * @param grid The grid to search within.
 * @return The count of pattern appearances.
 */
int CountBottomPatternAppearances(const Grid& grid) {
  int count = 0;
  int rows = grid.size();
  if (rows == 0) return 0;
  int cols = grid[0].size();

  for (int r = 0; r < rows - 2; ++r) {
    for (int c = 0; c < cols - 2; ++c) {
      if (grid[r][c] == 'S' && grid[r][c + 2] == 'S' && grid[r + 1][c + 1] == 'A' && grid[r + 2][c] == 'M' &&
          grid[r + 2][c + 2] == 'M') {
        count++;
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

  Grid grid;
  std::string line;
  while (std::getline(input, line)) {
    std::vector<char> row(line.begin(), line.end());
    grid.push_back(row);
  }
  input.close();

  int total_count = 0;
  total_count += CountLeftPatternAppearances(grid);
  total_count += CountUpperPatternAppearances(grid);
  total_count += CountRightPatternAppearances(grid);
  total_count += CountBottomPatternAppearances(grid);

  std::cout << "X-MAS appears " << total_count << " times in the grid." << std::endl;

  return EXIT_SUCCESS;
}