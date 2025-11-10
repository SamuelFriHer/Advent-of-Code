/**
 * Advent of Code 2024 - Day 5 - Part Two
 * https://adventofcode.com/2024/day/5
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/**
 * @brief Gets all the ordering rules from the input file.
 * @param input The input file stream.
 * @param ordering_rules A multimap to store "after" ordering rules.
 */
void GetOrderingRules(std::ifstream& input, std::multimap<int, int>& ordering_rules) {
  std::string line;
  while (std::getline(input, line)) {
    // Empty line, stop
    if (line.empty()) {
      break;
    }
    // Each line is expected to be in the format "n|m"
    size_t delimiter_pos = line.find('|');
    if (delimiter_pos == std::string::npos) {
      std::cerr << "Error: Invalid line format: " << line << std::endl;
      continue;
    }
    // Parse the numbers
    int n = std::stoi(line.substr(0, delimiter_pos));
    int m = std::stoi(line.substr(delimiter_pos + 1));
    ordering_rules.insert({n, m});
  }
}

/**
 * @brief Gets all sequences from the input file.
 * @param input The input file stream.
 * @param sequences A vector to store the sequences.
 */
void GetSequences(std::ifstream& input, std::vector<std::vector<int>>& sequences) {
  std::string line;
  while (std::getline(input, line)) {
    // Each line is expected to be a sequence of integers separated by commas
    std::vector<int> sequence;
    size_t start = 0;
    size_t end = line.find(',');
    while (end != std::string::npos) {
      sequence.push_back(std::stoi(line.substr(start, end - start)));
      start = end + 1;
      end = line.find(',', start);
    }
    sequence.push_back(std::stoi(line.substr(start)));
    sequences.push_back(sequence);
  }
}

/**
 * @brief Filters sequences based on ordering rules.
 * @param sequences The vector of sequences to filter.
 * @param ordering_rules The "after" ordering rules.
 * @return A vector of invalid sequences.
 */
std::vector<std::vector<int>> FilterSequences(const std::vector<std::vector<int>>& sequences,
                                              const std::multimap<int, int>& ordering_rules) {
  std::vector<std::vector<int>> invalid_sequences;

  for (const auto& sequence : sequences) {
    bool is_valid = true;
    // Check each ordering rule
    for (const auto& [n, m] : ordering_rules) {
      auto it_n = std::find(sequence.begin(), sequence.end(), n);
      auto it_m = std::find(sequence.begin(), sequence.end(), m);
      if (it_n != sequence.end() && it_m != sequence.end() && it_n > it_m) {
        is_valid = false;
        break;
      }
    }
    if (!is_valid) {
      invalid_sequences.push_back(sequence);
    }
  }

  return invalid_sequences;
}

/**
 * @brief Sorts the invalid sequences to fulfill the ordering rules.
 * @param invalid_sequences The vector of invalid sequences to sort.
 * @param ordering_rules The "after" ordering rules.
 * @return A vector of valid sequences.
 */
std::vector<std::vector<int>> SortInvalidSequences(const std::vector<std::vector<int>>& invalid_sequences,
                                                   const std::multimap<int, int>& ordering_rules) {
  std::vector<std::vector<int>> valid_sequences;

  // Sort each invalid sequence to fulfill the ordering rules
  for (const auto& sequence : invalid_sequences) {
    std::vector<int> sorted_sequence = sequence;
    std::sort(sorted_sequence.begin(), sorted_sequence.end(), [&](int a, int b) {
      // Check if there's an ordering rule for a and b
      auto range = ordering_rules.equal_range(a);
      return std::none_of(range.first, range.second, [&](const auto& rule) { return rule.second == b; });
    });
    valid_sequences.push_back(sorted_sequence);
  }

  return valid_sequences;
}

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }

  std::multimap<int, int> ordering_rules;
  GetOrderingRules(input, ordering_rules);

  std::vector<std::vector<int>> sequences;
  GetSequences(input, sequences);

  auto invalid_sequences = FilterSequences(sequences, ordering_rules);
  invalid_sequences = SortInvalidSequences(invalid_sequences, ordering_rules);

  int total_sum = 0;
  for (const auto& sequence : invalid_sequences) {
    total_sum += sequence[sequence.size() / 2];
  }

  std::cout << "Total Sum of Middle Elements: " << total_sum << std::endl;
  return EXIT_SUCCESS;
}