/**
 * Advent of Code 2024 - Day 4
 * https://adventofcode.com/2024/day/4
 *
 * @author Samuel Frías Hernández
 */

function part1(): void {
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
        if (characters[i][j] === 'X') {
          if (
            j + 3 < characters[i].length &&
            characters[i][j + 1] + characters[i][j + 2] + characters[i][j + 3] === 'MAS'
          ) {
            appearances++;
          }
          if (j - 3 >= 0 && characters[i][j - 1] + characters[i][j - 2] + characters[i][j - 3] === 'MAS') {
            appearances++;
          }
          if (
            i + 3 < characters.length &&
            characters[i + 1][j] + characters[i + 2][j] + characters[i + 3][j] === 'MAS'
          ) {
            appearances++;
          }
          if (i - 3 >= 0 && characters[i - 1][j] + characters[i - 2][j] + characters[i - 3][j] === 'MAS') {
            appearances++;
          }
          if (
            i + 3 < characters.length &&
            j + 3 < characters[i].length &&
            characters[i + 1][j + 1] + characters[i + 2][j + 2] + characters[i + 3][j + 3] === 'MAS'
          ) {
            appearances++;
          }
          if (
            i - 3 >= 0 &&
            j - 3 >= 0 &&
            characters[i - 1][j - 1] + characters[i - 2][j - 2] + characters[i - 3][j - 3] === 'MAS'
          ) {
            appearances++;
          }
          if (
            i + 3 < characters.length &&
            j - 3 >= 0 &&
            characters[i + 1][j - 1] + characters[i + 2][j - 2] + characters[i + 3][j - 3] === 'MAS'
          ) {
            appearances++;
          }
          if (
            i - 3 >= 0 &&
            j + 3 < characters[i].length &&
            characters[i - 1][j + 1] + characters[i - 2][j + 2] + characters[i - 3][j + 3] === 'MAS'
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

part1();
