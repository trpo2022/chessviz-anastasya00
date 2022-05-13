#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8
//#include "move.c"
//#include "print_chess_board.c"
#include "libchessviz/functions.h"

int pawn_move(
        char (*chess_board)[BOARD_SIZE],
        int board_size,
        int number_move,
        int x1,
        int y1,
        int x2,
        int y2)
{
    if (x1 == x2 && y1 == y2) {
        printf("Вы не походили!");
    }
    number_move++;

    if (number_move == 1) {
        if (chess_board[y1][x1] == 'p') {
            if ((x1 == x2 && abs(y1 - y2) > 2) || (y1 == y2 && x2 >= x1)
                || (y1 == y2 && x1 <= x2)) {
                printf("Такой ход сделать нельзя.\n");
            } else {
                move(chess_board, BOARD_SIZE, x1, y1, x2, y2);
            }
        }

        else if (chess_board[y1][x1] == 'P') {
            if ((x1 == x2 && abs(y1 - y2) > 2) || (y1 == y2 && x1 > x2)
                || (y1 == y2 && x1 < x2)) {
                printf("Такой ход сделать нельзя.\n");
            } else {
                move(chess_board, BOARD_SIZE, x1, y1, x2, y2);
            }
        }
        number_move++;
    }

    else {
        if (chess_board[y1][x1] == 'p') {
            if ((x1 == x2 && abs(y1 - y2) > 1) || (y1 == y2 && abs(x2 - x1) > 1)
                || (abs(y1 - y2) > 1 && abs(x2 - x1) > 1)) {
                printf("Такой ход сделать нельзя.\n");
            } else {
                move(chess_board, BOARD_SIZE, x1, y1, x2, y2);
            }
        }

        else if (chess_board[y1][x1] == 'P') {
            if ((x1 == x2 && abs(y1 - y2)) || (y1 == y2 && abs(x2 - x1) > 1)
                || (abs(y1 - y2) > 1 && abs(x2 - x1) > 1)) {
                printf("Такой ход сделать нельзя.\n");
            } else {
                move(chess_board, BOARD_SIZE, x1, y1, x2, y2);
            }
        }
        number_move++;
    }
}
