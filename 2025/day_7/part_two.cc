/**
 * Advent of Code 2025 - Day 7 - Part Two
 * https://adventofcode.com/2025/day/7
 */

#include <fstream>
#include <iostream>
#include <map>
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
 * @brief Counts distinct paths for a single row.
 * @param current_counts Map of column -> number of active timelines (particles).
 * @param next_counts Map to store the counts for the next row.
 * @param grid The grid of characters.
 * @param r The current row index.
 * @param distinct_timelines Reference to the total distinct timelines counter.
 */
void CountDistinctPathsForRow(std::map<int, long long>& current_counts, std::map<int, long long>& next_counts,
                              const std::vector<std::string>& grid, int r, long long& distinct_timelines) {
  for (auto const& [col, count] : current_counts) {
    if (col < 0 || col >= grid[0].size()) {
      continue;
    }

    char c = grid[r][col];
    if (c == '^') {
      int left_col = col - 1;
      int right_col = col + 1;

      if (left_col < 0 || left_col >= grid[0].size()) {
        distinct_timelines += count;  // Exited manifold sideways
      } else {
        next_counts[left_col] += count;
      }
      if (right_col < 0 || right_col >= grid[0].size()) {
        distinct_timelines += count;  // Exited manifold sideways
      } else {
        next_counts[right_col] += count;
      }
    } else {
      if (col < 0 || col >= grid[0].size()) {
        distinct_timelines += count;
      } else {
        next_counts[col] += count;
      }
    }
  }
}

/**
 * @brief Simulates the quantum timelines and counts distinct paths.
 * @param grid The grid of characters.
 * @return The total number of distinct timelines.
 */
long long CountTimelines(const std::vector<std::string>& grid) {
  int height = grid.size();
  int width = grid[0].size();
  int start_col = FindStartColumn(grid);

  // Map of column -> number of active timelines (particles)
  std::map<int, long long> current_counts;
  current_counts[start_col] = 1;

  long long distinct_timelines = 0;

  for (int r = 1; r < height; ++r) {
    std::map<int, long long> next_counts;
    CountDistinctPathsForRow(current_counts, next_counts, grid, r, distinct_timelines);
    current_counts = next_counts;
  }

  // Any beams remaining in current_counts have exited the bottom of the grid
  for (auto const& [col, count] : current_counts) {
    distinct_timelines += count;
  }
  return distinct_timelines;
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

  long long result = CountTimelines(grid);
  std::cout << "Total distinct timelines: " << result << std::endl;

  return EXIT_SUCCESS;
}