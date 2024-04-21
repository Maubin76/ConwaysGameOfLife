#include "ConwaysGameOfLife.h"

void main() {
    // Create board with all cells dead
    char **board = createBoard();
    // Randomize board with ALIVE_CHANCE chance of a cell being alive
    randomizeBoard(board);
    sleep(GENERATION_RATE);
    while(1){
        // Clear screen
        system("clear");
        // Print board
        printBoard(board);
        // Wait 1s
        sleep(GENERATION_RATE);
        // Calculate next generation
        nextGeneration(board);
        // print the board
        printBoard(board);
    }
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

void nextGeneration(char **board){
    char **newBoard = createBoard();
    for(int i = 0; i < BOARD_HEIGHT; i++){
        for(int j = 0; j < BOARD_WIDTH; j++){
            int neighbors = countNeighbors(board, i, j);
            if(board[i][j] == ALIVE){
                if(neighbors < 2 || neighbors > 3){
                    newBoard[i][j] = DEAD;
                } else {
                    newBoard[i][j] = ALIVE;
                }
            } else {
                if(neighbors == 3){
                    newBoard[i][j] = ALIVE;
                } else {
                    newBoard[i][j] = DEAD;
                }
            }
        }
    }
    for(int i = 0; i < BOARD_HEIGHT; i++){
        for(int j = 0; j < BOARD_WIDTH; j++){
            board[i][j] = newBoard[i][j];
        }
    }
}

int countNeighbors(char **board, int x, int y){
    int count = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0){
                continue;
            }
            if(x + i < 0 || x + i >= BOARD_HEIGHT || y + j < 0 || y + j >= BOARD_WIDTH){
                continue;
            }
            if(board[x + i][y + j] == ALIVE){
                count++;
            }
        }
    }
    return count;
}