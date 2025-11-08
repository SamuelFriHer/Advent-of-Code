/**
 * Advent of Code 2024 - Day 3 - Part Two
 * https://adventofcode.com/2024/day/3
 */

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Extracts from a string all the sequences between /do()/ and /don't()/,
 *        including the fragment before the first /don't()/ and after the last /do()/.
 * @param line The input string to search within.
 * @return A vector of strings representing the extracted sequences.
 */
std::vector<std::string> extractDoDontSequences(const std::string& line) {
  std::vector<std::string> sequences;

  // Find the first "don't()"
  std::smatch match;
  if (std::regex_search(line, match, std::regex(R"(don't\(\))"))) {
    sequences.push_back(match.prefix().str());
  }
  // Find the last "do()"
  std::string reverse_line(line.rbegin(), line.rend());
  if (std::regex_search(reverse_line, match, std::regex(R"(do\(\))"))) {
    sequences.push_back(std::string(match.prefix().str().rbegin(), match.prefix().str().rend()));
  }

  // Find all sequences between "do()" and "don't()"
  std::regex do_dont_regex(R"(do\(\)(.*?)don't\(\))");
  auto words_begin = std::sregex_iterator(line.begin(), line.end(), do_dont_regex);
  auto words_end = std::sregex_iterator();

  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    sequences.push_back((*i)[1].str());
  }
  return sequences;
}

/**
 * @brief Extracts from a string all the sequences matching /mul\(\d+,\d+\)/
 * @param line The input string to search within.
 * @return A vector of pairs of integers representing the extracted multiplication operations.
 */
std::vector<std::pair<int, int>> extractMultiplications(const std::string& line) {
  std::vector<std::pair<int, int>> multiplications;

  std::regex mul_regex(R"(mul\((\d+),(\d+)\))");
  auto words_begin = std::sregex_iterator(line.begin(), line.end(), mul_regex);
  auto words_end = std::sregex_iterator();

  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    multiplications.push_back({std::stoi((*i)[1].str()), std::stoi((*i)[2].str())});
  }
  return multiplications;
}

int main() {
  std::ifstream inputFile("input.txt");
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return EXIT_FAILURE;
  }

  std::string line;
  std::string text;
  std::vector<std::pair<int, int>> all_multiplications;
  while (std::getline(input, line)) {
    text += line;
  }
  input.close();

  auto sequences = extractDoDontSequences(text);
  for (const auto& seq : sequences) {
    auto multiplications = extractMultiplications(seq);
    all_multiplications.insert(all_multiplications.end(), multiplications.begin(), multiplications.end());
  }

  int total_sum = 0;
  for (const auto& mul : all_multiplications) {
    total_sum += mul.first * mul.second;
  }
  std::cout << "If you add up all of the results of the multiplications, you get: " << total_sum << std::endl;
}