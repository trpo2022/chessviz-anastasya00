#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

void move(char (*chess_board)[BOARD_SIZE], int x1, int y1, int x2, int y2)
{
    chess_board[y2][x2] = chess_board[y1][x1];
    chess_board[y1][x1] = ' ';
}
