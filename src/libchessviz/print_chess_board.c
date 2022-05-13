#include <stdio.h>
#define BOARD_SIZE 8
#include "libchessviz/functions.h"

void print_chess_board(char (*chess_board)[BOARD_SIZE], int board_size)
{
    for (int i = 0; i < board_size; i++) {
        printf("%d ", board_size - i);

        for (int j = 0; j < board_size; j++) {
            printf("%c ", chess_board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g j\n");

    printf("\n\n");
}
