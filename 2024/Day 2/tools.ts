/**
 * Advent of Code 2024 - Day 2
 * https://adventofcode.com/2024/day/2
 *
 * @author Samuel Frías Hernández
 */

/**
 * Checks if a report is safe.
 *
 * A report only counts as safe if both of the following are true:
 *  - The levels are either all increasing or all decreasing.
 *  - Any two adjacent levels differ by at least one and at most three.
 *
 * @param report The report to check.
 */
export function isSafe(report: number[]): boolean {
  let increasing = true;
  let decreasing = true;

  for (let i = 1; i < report.length; i++) {
    if (report[i] > report[i - 1]) {
      decreasing = false;
    } else if (report[i] < report[i - 1]) {
      increasing = false;
    }
    if (report[i] === report[i - 1] || Math.abs(report[i] - report[i - 1]) > 3) {
      return false;
    }
  }
  return increasing || decreasing;
}
