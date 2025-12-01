/**
 * Advent of Code 2025 - Day 1 - Part One
 * https://adventofcode.com/2025/day/1
 */

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Starts the movement in the 50th postion, in a dial of 100 positions (0-99).
 * @param moves A vector of pairs representing direction and distance.
 * @return The number of times position 0 is visited.
 */
int CountVisitsToZero(const std::vector<std::pair<char, int>>& moves) {
  const int dial_size = 100;
  int position = 50;  // Start at position 50
  int visits_to_zero = 0;

  for (const auto& [direction, distance] : moves) {
    for (int i = 0; i < distance; ++i) {
      if (direction == 'L') {
        position = (position - 1 + dial_size) % dial_size;
      } else if (direction == 'R') {
        position = (position + 1) % dial_size;
      }
    }

    if (position == 0) {
      ++visits_to_zero;
    }
  }

  return visits_to_zero;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }
  std::vector<std::pair<char, int>> moves;
  std::string line;

  while (std::getline(input, line)) {
    char direction = line[0];
    int distance = std::stoi(line.substr(1));
    moves.emplace_back(direction, distance);
  }

  int visits = CountVisitsToZero(moves);
  std::cout << "The dial points to 0 a total of " << visits << " times." << std::endl;

  return EXIT_SUCCESS;
}