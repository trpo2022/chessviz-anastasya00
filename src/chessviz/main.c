#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOARD_SIZE 8
#define N 6

#include <libchessviz/functions.h>

int main()
{
    char* command;
    command = malloc(sizeof(char) * N);

    const char exit[N] = "exit";

    printf("Если хотите окончить игру, напишите: exit\n");

    char chess_board[BOARD_SIZE][BOARD_SIZE]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    print_chess_board(chess_board, BOARD_SIZE);

    while (strcmp(command, exit) != 0) {
        scanf("%s", command);

        if (strcmp(command, exit) == 0) {
            return 0;
        }

        int x1, y1, x2, y2;
        int number_move = 0;

        x1 = coordX(command[0]);
        y1 = coordY(command[1]);
        x2 = coordX(command[3]);
        y2 = coordY(command[4]);

        if (chess_board[x1][y1] == 'P' || chess_board[x1][y1] == 'p') {
            pawn_move(chess_board, BOARD_SIZE, number_move, x1, y1, x2, y2);
        }

        else {
            move(chess_board, BOARD_SIZE, x1, y1, x2, y2);
        }
        print_chess_board(chess_board, BOARD_SIZE);
    }

    return 0;
}
