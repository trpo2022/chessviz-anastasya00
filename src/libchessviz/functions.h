#pragma once
#define BOARD_SIZE 8

void print_chess_board(char (*chess_board)[BOARD_SIZE], int board_size);
void move(
        char (*chess_board)[BOARD_SIZE],
	int board_size,
        int x1,
        int y1,
        int x2,
        int y2);
int pawn_move(
        char (*chess_board)[BOARD_SIZE],
	int board_size,
        int number_move,
        int x1,
        int y1,
        int x2,
        int y2);
int coordX(char x);
int coordY(char y);
