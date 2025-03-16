/**
 * Advent of Code 2024 - Day 5
 * https://adventofcode.com/2024/day/5
 *
 * @author Samuel Frías Hernández
 */

/**
 * Check if the given sequence of numbers is correct
 * @param sequence The sequence of numbers
 * @param rules The ordering rules
 * @returns True if the sequence is correct, false otherwise
 */
export function isCorrect(sequence: number[], rules: { first: number; second: number }[]): boolean {
  for (let i = 0; i < sequence.length - 1; i++) {
    for (let j = i + 1; j < sequence.length; j++) {
      const first = sequence[i];
      const second = sequence[j];
      if (rules.some((rule) => rule.first === second && rule.second === first)) {
        return false;
      }
    }
  }
  return true;
}

/**
 * Sort a sequence of numbers
 * @param sequence The sequence of numbers
 * @param rules The ordering rules
 * @returns The sorted sequence
 */
export function sort(sequence: number[], rules: { first: number; second: number }[]): number[] {
  for (let i = 0; i < sequence.length - 1; i++) {
    for (let j = i + 1; j < sequence.length; j++) {
      const first = sequence[i];
      const second = sequence[j];
      if (rules.some((rule) => rule.first === second && rule.second === first)) {
        const temp = sequence[i];
        sequence[i] = sequence[j];
        sequence[j] = temp;
      }
    }
  }
  return sequence;
}
