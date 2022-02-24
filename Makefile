all: chess game
chess: chess_game.c
	gcc -Wall -Werror -o chess chess_game.c
game:
./chess
