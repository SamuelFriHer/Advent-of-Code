/**
 * Advent of Code 2024 - Day 5
 * https://adventofcode.com/2024/day/5
 *
 * @author Samuel Frías Hernández
 */

import { isCorrect } from './tools';

function part1(): void {
  const readLine = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
  });

  let space: boolean = false;
  let orderingRules: { first: number; second: number }[] = [];
  let pageNumbers: number[][] = [];

  readLine.on('line', (line: string) => {
    if (line === '' && space) {
      readLine.close();
    }
    if (line === '' && !space) {
      space = true;
    }
    if (line.includes('|')) {
      const [first, second] = line.split('|').map(Number);
      orderingRules.push({ first, second });
    }
    if (line.includes(',')) {
      const numbers = line.split(',').map(Number);
      pageNumbers.push(numbers);
    }
  });

  readLine.on('close', () => {
    let correctSequences: number[][] = [];
    for (let sequence of pageNumbers) {
      if (isCorrect(sequence, orderingRules)) {
        correctSequences.push(sequence);
      }
    }
    let result: number = 0;
    for (let sequence of correctSequences) {
      result += sequence[Math.floor(sequence.length / 2)];
    }
    console.log(result);
    process.exit(0);
  });
}

part1();
