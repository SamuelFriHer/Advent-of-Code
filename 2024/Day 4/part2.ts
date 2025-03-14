/**
 * Advent of Code 2024 - Day 4
 * https://adventofcode.com/2024/day/4
 *
 * @author Samuel Frías Hernández
 */

function part2(): void {
  const readLine = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
  });

  let wordSearch: string[] = [];
  readLine.on('line', (line: string) => {
    if (line.length === 0) {
      readLine.close();
    }
    wordSearch.push(line);
  });

  readLine.on('close', () => {
    let characters: string[][] = [];
    for (let row of wordSearch) {
      characters.push(row.split(''));
    }

    let appearances: number = 0;
    for (let i = 0; i < characters.length; i++) {
      for (let j = 0; j < characters[i].length; j++) {
        if (
          characters[i][j] === 'A' &&
          i - 1 >= 0 &&
          j - 1 >= 0 &&
          i + 1 < characters.length &&
          j + 1 < characters[i].length
        ) {
          if (
            characters[i - 1][j - 1] === 'M' &&
            characters[i - 1][j + 1] === 'M' &&
            characters[i + 1][j - 1] === 'S' &&
            characters[i + 1][j + 1] === 'S'
          ) {
            appearances++;
          } else if (
            characters[i - 1][j - 1] === 'S' &&
            characters[i - 1][j + 1] === 'S' &&
            characters[i + 1][j - 1] === 'M' &&
            characters[i + 1][j + 1] === 'M'
          ) {
            appearances++;
          } else if (
            characters[i - 1][j - 1] === 'M' &&
            characters[i - 1][j + 1] === 'S' &&
            characters[i + 1][j - 1] === 'M' &&
            characters[i + 1][j + 1] === 'S'
          ) {
            appearances++;
          } else if (
            characters[i - 1][j - 1] === 'S' &&
            characters[i - 1][j + 1] === 'M' &&
            characters[i + 1][j - 1] === 'S' &&
            characters[i + 1][j + 1] === 'M'
          ) {
            appearances++;
          }
        }
      }
    }
    console.log(appearances);
    process.exit(0);
  });
}

part2();
