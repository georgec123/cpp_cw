/*This file contains functions that check the state of the game: print the board and verify if there is a winner*/
#include "header.h"

void printing_board(char board[MAX][MAX]) {
	int i, j;
	printf("\n");

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

int game_over(char board[MAX][MAX], int player) {
	/*
	This piece of code verifies if a player is the winner
	There are three positbilities to win: whole row, whole column, diagonal
	
	Returns 0 if no winner. Returns player number if there is a winner
	*/

	for (int i = 0; i < MAX; i++)
	{
		// Check rows
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return player;
	}
	for (int i = 0; i < MAX; i++)
	{
		// Check columns	
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return player;
	}
	
	// Check diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return player;
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
		return player;
	
	return 0;
}