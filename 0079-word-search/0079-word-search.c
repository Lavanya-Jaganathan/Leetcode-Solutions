#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int row, int col, int rows, int cols, char* word, int index) {
    
    if (index == strlen(word)) {
        return true;
    }
    if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[index]) {
        return false;
    }
    char temp = board[row][col];
    board[row][col] = '#';
    bool found = dfs(board, row + 1, col, rows, cols, word, index + 1) ||  // Down
                 dfs(board, row - 1, col, rows, cols, word, index + 1) ||  // Up
                 dfs(board, row, col + 1, rows, cols, word, index + 1) ||  // Right
                 dfs(board, row, col - 1, rows, cols, word, index + 1);    // Left
    board[row][col] = temp;

    return found;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = boardColSize[0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == word[0] && dfs(board, i, j, rows, cols, word, 0)) {
                return true;
            }
        }
    }

    return false;
}
