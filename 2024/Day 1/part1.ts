/**
 * Advent of Code 2024 - Day 1
 * https://adventofcode.com/2024/day/1
 *
 * @author Samuel Frías Hernández
 */

function part1(): void {
  const rl = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
  });

  let firstList: number[] = [];
  let secondList: number[] = [];
  rl.on('line', (line: string) => {
    if (line.length === 0) {
      rl.close();
    } else {
      const numbers = line.split(/\s+/).map(Number);
      firstList.push(numbers[0]);
      secondList.push(numbers[1]);
    }
  });

  rl.on('close', () => {
    firstList.sort((a, b) => a - b);
    secondList.sort((a, b) => a - b);

    let result: number = 0;
    for (let i = 0; i < firstList.length; i++) {
      result += Math.abs(firstList[i] - secondList[i]);
    }
    console.log(result);
    process.exit(0);
  });
}

part1();
