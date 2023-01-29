/*This file constains the functions that allow the player to input a move and modify the board*/
/*The functions are symmetrical*/
#include "header.h"

void player1_move(char board[MAX][MAX]) {
	int move, row, col;
	printf("Player 1, please input the position of the move for the 3x3 grid:\n");
	scanf("%d", &move);
	
	/*We convert the movement number into a row, col format*/
	move--;
	row = move / MAX;
	col = move % MAX;
	
	/*We check that the movement is possible: it has to be in the grid and not already done*/
	while (move + 1 < 1 || move + 1 > 9 || board[row][col] == 'X' || board[row][col] == 'O')
	{
		printf("That move is not valid, insert another:\n");
		scanf("%d", &move);
		move--;
		row = move / MAX;
		col = move % MAX;
	}

	/*Finally the grid is changed*/
	board[row][col] = 'X';
}

void player2_move(char board[MAX][MAX]) {
	int move, row, col;
	printf("Player 2, please input the position of the move for the 3x3 grid:\n");
	scanf("%d", &move);
	
	/*We convert the movement number into a row, col format*/
	move--;
	row = move / MAX;
	col = move % MAX;

	/*We check that the movement is possible: it has to be in the grid and not already done*/
	while (move + 1 < 1 || move + 1 > 9 || board[row][col] == 'X' || board[row][col] == 'O')
	{
		printf("That move is not valid, insert another:\n");
		scanf("%d", &move);
		move--;
		row = move / MAX;
		col = move % MAX;
	}

	/*Finally the grid is changed*/
	board[row][col] = 'O';
}