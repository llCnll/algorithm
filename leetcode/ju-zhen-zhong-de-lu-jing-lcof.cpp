#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool dfs(int vis[][210], char**board, int boardSize, int colSize, char * word, int i, int j, int k) {
    if (i < 0 || j < 0 || i >= boardSize || j >= colSize || vis[i][j] == 1) return false;

    if (word[k] != board[i][j]) return false;

    k++;

    if (k == strlen(word)) return true;

    vis[i][j] = 1;
    bool res = dfs(vis, board, boardSize, colSize, word, i, j+1, k)
        || dfs(vis, board, boardSize, colSize, word, i+1, j, k)
        || dfs(vis, board, boardSize, colSize, word, i-1, j, k)
        || dfs(vis, board, boardSize, colSize, word, i, j-1, k);
    vis[i][j] = 0;
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){

    int vis[210][210] = {0};

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (dfs(vis, board, boardSize, boardColSize[i], word, i, j, 0)) return true;
        }
    }

    return false;
}

int main() {

    char ** board = (char**)malloc(sizeof(char*)*3);

    for (int i = 0; i < 3; ++i) {
        board[i] = (char*)calloc(4, sizeof(char));
    }

    int colSize[] = {4, 4, 4};

    strcpy(board[0], "ABCE");
    strcpy(board[1], "SFCS");
    strcpy(board[2], "ADEE");

    printf("%d\n", exist(board, 3, colSize, "ABCCED"));

    return 0;
}

