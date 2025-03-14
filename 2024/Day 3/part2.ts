/**
 * Advent of Code 2024 - Day 3
 * https://adventofcode.com/2024/day/3
 *
 * @author Samuel Frías Hernández
 */

function part2(): void {
  const readLine = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
  });

  let program: string = '';
  readLine.on('line', (line: string) => {
    if (line.length === 0) {
      readLine.close();
    }
    program += line;
  });

  readLine.on('close', () => {
    const instructions = program.match(/mul\(\d+,\d+\)|do\(\)|don't\(\)/g) || [];

    let result: number = 0;
    let enabled: boolean = true;
    for (const instruction of instructions) {
      if (instruction === 'do()') {
        enabled = true;
      } else if (instruction === "don't()") {
        enabled = false;
      } else if (enabled) {
        const [a, b] = instruction.match(/\d+/g)!.map(Number);
        result += a * b;
      }
    }
    console.log(result);
    process.exit(0);
  });
}

part2();
