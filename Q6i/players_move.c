/*This file constains the functions that allow the player to input a move and modify the board*/
/*The functions are symmetrical*/
#include "header.h"


int player_input(char board[MAX][MAX], int player){
	
	/*We ask the player to input the movement*/
	int move, row, col;	
	printf("Player %d, please input the position of the move for the 3x3 grid:\n", player);
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

	return move;
}

void player_move(char board[MAX][MAX], int player) {
	
	int move = player_input(board, player);
	int row = move / MAX;
	int col = move % MAX;

	/*Finally the grid is changed*/
	char move_char;
	if (player == 1) {
		move_char = 'X';
	}
	else {
		move_char = 'O';
	}
	board[row][col] = move_char;
}
