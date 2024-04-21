#define CONWAYSGAMEOFLIFE_H
#ifdef CONWAYSGAMEOFLIFE_H

// These dimensions depend on the terminal size, they are adapted to mine
#define BOARD_WIDTH 157
#define BOARD_HEIGHT 47
#define ALIVE_CHANCE 0.1
#define GENERATION_RATE 1
#define ALIVE 'O'
#define DEAD '.'

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printBoard(char **);
char** createBoard();
void randomizeBoard(char **);
void nextGeneration(char **);
int countNeighbors(char **, int, int);

#endif