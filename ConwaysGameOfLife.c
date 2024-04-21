#include "ConwaysGameOfLife.h"

void main() {
    // Create board with all cells dead
    char **board = createBoard();
    // Randomize board with ALIVE_CHANCE chance of a cell being alive
    randomizeBoard(board);
    printBoard(board);

}

char** createBoard(){
    char **board = (char **)malloc(BOARD_HEIGHT * sizeof(char *));
    for(int i = 0; i < BOARD_HEIGHT; i++){
        board[i] = (char *)malloc(BOARD_WIDTH * sizeof(char));
        for(int j = 0; j < BOARD_WIDTH; j++){
            board[i][j] = DEAD;
        }
    }
    return board;
}

void printBoard(char **board){
    for(int i = 0; i < BOARD_HEIGHT; i++){
        for(int j = 0; j < BOARD_WIDTH; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void randomizeBoard(char **board){
    for(int i = 0; i < BOARD_HEIGHT; i++){
        for(int j = 0; j < BOARD_WIDTH; j++){
            if((rand() % 100) < ALIVE_CHANCE * 100){
                board[i][j] = ALIVE;
            }
        }
    }
}