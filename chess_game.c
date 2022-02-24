#include <stdio.h>
#define N 8

int main()
{
	char chess_board[N][N]={{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
				{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
				{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

	for(int i=0; i<N; i++){
		printf("%d ", N-i);

		for(int j=0; j<N; j++){
			printf("%c ", chess_board[i][j]);
		}
		printf("\n");
	}

	printf("  a b c d e f g j\n");

	return 0;
}
