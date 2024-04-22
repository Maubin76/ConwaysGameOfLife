#include "ConwaysGameOfLife.h"

int main(int argc, char *argv[]) {

    system("clear"); // Clear the terminal
    char **board;

    // Check if the user provided a file
    if(argc==3){
        char *filename = argv[1];
        GENERATION_RATE = atoi(argv[2])*100000; // Get the generation rate
        getBoardSize(filename); // Get the size of the board in the file
        board = readTextFile(filename);
        printBoard(board); // Print the board
    } else {
        getTerminalSize(&BOARD_HEIGHT, &BOARD_WIDTH); // Get the terminal size
        board = createBoard(); // Create board with all cells dead
        randomizeBoard(board); // Randomize the board
        printBoard(board); // Print the board
    }

    while(1){
        usleep(GENERATION_RATE); // Sleep to let the board printed
        system("clear"); // Clear the terminal
        nextGeneration(board); // Modify the board for the next generation
        printBoard(board); // Print the board
        TOTAL_GENERATION++; // Increment the generation number
        printf("T = %d\n", TOTAL_GENERATION); // Print the generation number
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

void getTerminalSize(int *rows, int *cols) {
    struct winsize ws; // Struct to store the terminal size
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); // Get the terminal size
    *rows = ws.ws_row; 
    *cols = ws.ws_col;
}

char** readTextFile(char* filename) {
    FILE* file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) { // Check if the file was opened
        fprintf(stderr, "Error : An error occured when opening the file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char** board = (char**)malloc(BOARD_HEIGHT * sizeof(char*)); // Allocate memory for the board
    if (board == NULL) { // Check if the memory was allocated
        fprintf(stderr, "Error : Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < BOARD_HEIGHT; i++) { // Browse the lines
        board[i] = (char*)malloc(BOARD_WIDTH * sizeof(char)); // Allocate memory for each row
        if (board[i] == NULL) { // Check if the memory was allocated
            fprintf(stderr, "Error : Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    char c; // Variable to store the current character
    int i = 0, j = 0; // Variables to store the current position
    while ((c = fgetc(file)) != EOF) { // Browse the file
        if (c == '\n') { // Check if the character is a new line
            i++; // Increment the row
            j = 0; // Reset the column
        } else if (i < BOARD_HEIGHT && j < BOARD_WIDTH) { // Check if the position is in bounds
            board[i][j] = c; // Store the character in the board
            j++; // Increment the column
        }
    }
    fclose(file);
    return board;
}

void getBoardSize(char* filename) {
    FILE* file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) {
        fprintf(stderr, "Error : An error occured when opening the file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char c; // Variable to store the current character
    while ((c = fgetc(file)) != EOF) { // Browse the file
        if (c == '\n') { // Check if the character is a new line
            BOARD_HEIGHT++; // Increment the number of rows
        } else {
            if (BOARD_HEIGHT == 0) BOARD_WIDTH++; // Increment the number of columns
        }
    }
    BOARD_HEIGHT++;
    fclose(file); // Close the file
}