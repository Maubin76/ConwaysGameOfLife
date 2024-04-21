#include "ConwaysGameOfLife.h"

void main() {
    char **board = createBoard(); // Create board with all cells dead

    system("clear"); // Clear the terminal
    randomizeBoard(board); // Randomize the board
    printBoard(board); // Print the board

    while(1){
        sleep(GENERATION_RATE); // Sleep to let the board printed
        system("clear"); // Clear the terminal
        nextGeneration(board); // Modify the board for the next generation
        printBoard(board); // Print the board
    }
}

char** createBoard(){
    char **board = (char **)malloc(BOARD_HEIGHT * sizeof(char *)); // Allocate memory for the board
    for(int i = 0; i < BOARD_HEIGHT; i++){ 
        board[i] = (char *)malloc(BOARD_WIDTH * sizeof(char)); // Allocate memory for each row
        for(int j = 0; j < BOARD_WIDTH; j++){
            board[i][j] = DEAD; // Set all cells to dead
        }
    }
    return board;
}

void printBoard(char **board){
    for(int i = 0; i < BOARD_HEIGHT; i++){ // Browse the lines
        for(int j = 0; j < BOARD_WIDTH; j++){ // Browse the columns
            printf("%c", board[i][j]); // Print the cell
        }
        printf("\n"); // Print a new line
    }
}

void randomizeBoard(char **board){
    for(int i = 0; i < BOARD_HEIGHT; i++){ // Browse the lines
        for(int j = 0; j < BOARD_WIDTH; j++){ // Browse the columns
            if((rand() % 100) < ALIVE_CHANCE * 100){ // Randomize the cell
                board[i][j] = ALIVE; // Set the cell to alive
            }
        }
    }
}

void nextGeneration(char **board){
    char **newBoard = createBoard(); // Create a new board
    for(int i = 0; i < BOARD_HEIGHT; i++){ // Browse the lines
        for(int j = 0; j < BOARD_WIDTH; j++){ // Browse the columns
            int neighbors = countNeighbors(board, i, j); // Count the number of alive neighbors
            if(board[i][j] == ALIVE){ 
                if(neighbors < 2 || neighbors > 3){ // Rule 1 and 3
                    newBoard[i][j] = DEAD; // Kill the cell
                } else {
                    newBoard[i][j] = ALIVE; // Keep the cell alive
                }
            } else {
                if(neighbors == 3){ // Rule 4
                    newBoard[i][j] = ALIVE; // Make the cell alive
                } else {
                    newBoard[i][j] = DEAD; // Keep the cell dead
                }
            }
        }
    }
    for(int i = 0; i < BOARD_HEIGHT; i++){ // Browse the lines
        for(int j = 0; j < BOARD_WIDTH; j++){ // Browse the columns
            board[i][j] = newBoard[i][j]; // Update the board
        }
    }
}

int countNeighbors(char **board, int x, int y){ 
    int count = 0; // Initialize the count
    for(int i = -1; i <= 1; i++){ // Browse the lines
        for(int j = -1; j <= 1; j++){ // Browse the columns
            if(i == 0 && j == 0){ // Skip the cell itself
                continue;
            }
            if(x + i < 0 || x + i >= BOARD_HEIGHT || y + j < 0 || y + j >= BOARD_WIDTH){ // Skip out of bounds cells
                continue;
            }
            if(board[x + i][y + j] == ALIVE){ // Check if the cell is alive
                count++; // Increment the count
            }
        }
    }
    return count;
}