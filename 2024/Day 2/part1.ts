/**
 * Advent of Code 2024 - Day 2
 * https://adventofcode.com/2024/day/2
 *
 * @author Samuel Frías Hernández
 */

import { isSafe } from './tools';

{
  const readLine = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
  });

  let reports: number[][] = [];
  readLine.on('line', (line: string) => {
    if (line.length === 0) {
      readLine.close();
    } else {
      reports.push(line.split(/\s+/).map(Number));
    }
  });

  readLine.on('close', () => {
    let count = 0;
    for (const report of reports) {
      if (isSafe(report)) {
        count++;
      }
    }
    console.log(count);
    process.exit(0);
  });
}
