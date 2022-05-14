#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libchessviz/funktions.h>
#define BOARD_SIZE 8

CTEST(ctest, writel)
{
	char *command = "Qd1xd3#";

	const int result = coordX(command[1]);
	const int expected1 = 3;

	ASSERT_EQUAL(expected, result);
}

CTEST(ctest, writel2)
{
	char *command = "a2-a3";

	const int result = coordY(command[1]);
	const int expected = 6;

	ASSERT_EQUAL(expected, result);
}

CTEST(ctest, writel3)
{
	char *command = "Bc1-c2";

	const int result = coordX(command[4]);
	const int expected = 2;

	ASSERT_EQUAL(expected, result);
}

CTEST(ctest, writel4)
{
	char *command = "Bc1-2c";

	const int result = coordX(command[4]);
	const int expected = -1;

	ASSERT_EQUAL(expected, result);
}

CTEST(ctest, writel5)
{
	char *command = "exit";

	const int result = strcmp(command, "exit");
	const int expected = 0;

	ASSERT_EQUAL(expected, result);
}

CTEST(ctest, writel6)
{

	char chess_board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
				  {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
				  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				  {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
				  {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

	char *command = "Ph2xh2#";
	int number = 1;

	if(strlen(command) == 5) {
		x1 = coordX(command[0]);
		y1 = coordY(command[1]);
		x2 = coordX(command[3]);
		y2 = coordY(command[4]);
	}
	if(strlen(command) == 6) {
		x1 = coordX(command[1]);
		y1 = coordY(command[2]);
		x2 = coordX(command[4]);
		y2 = coordY(command[5]);
	}
	if(strlen(command) == 5) {
		x1 = coordX(command[1]);
		y1 = coordY(command[2]);
		x2 = coordX(command[4]);
		y2 = coordY(command[5]);
	}

	const int result = pawn_move(chess_board, BOARD_SIZE, number, x1, y1, x2, y2);
	const int expected = -1;

	ASSERT_EQUAL(expected, result);
}


















