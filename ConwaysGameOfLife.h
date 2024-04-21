#define CONWAYSGAMEOFLIFE_H
#ifdef CONWAYSGAMEOFLIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// These dimensions depend on the terminal size, they are adapted to mine
#define BOARD_WIDTH 157
#define BOARD_HEIGHT 47
// The chance of a cell being alive when randomizing the board
#define ALIVE_CHANCE 0.1
// The time between generations in seconds
#define GENERATION_RATE 1
// The characters used to represent the cells
#define ALIVE 'O'
#define DEAD '.'

// Print the board to the terminal
void printBoard(char **);

// Create a board with all cells dead
char** createBoard();

// Randomize the board with a chance of a cell being alive
void randomizeBoard(char **);

/* Modify the board for the next generation
* Rules:
* 1. Any live cell with fewer than two live neighbors dies, as if by underpopulation.
* 2. Any live cell with two or three live neighbors lives on to the next generation.
* 3. Any live cell with more than three live neighbors dies, as if by overpopulation.
* 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/
void nextGeneration(char **);

// Count the number of alive neighbors of a cell
int countNeighbors(char **, int, int);

#endif