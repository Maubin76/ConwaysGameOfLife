#define CONWAYSGAMEOFLIFE_H
#ifdef CONWAYSGAMEOFLIFE_H

#define BOARD_WIDTH 155
#define BOARD_HEIGHT 45
#define ALIVE_CHANCE 0.1
#define ALIVE 'O'
#define DEAD '.'

#include <stdio.h>
#include <stdlib.h>

void printBoard(char **);
char** createBoard();
void randomizeBoard(char **);

#endif