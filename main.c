#include "header.h"

int main(void)
{
	/*Initialise the board*/
	char grid[MAX][MAX] = {{'1','2','3'},
						  {'4','5','6'},
						  {'7','8','9'}
						 };
	int victory = 0;//Victory represents the state of the game: 0 for draw and i for player i-th victory
	int moves = 1;
	
	/*Add a random number to decide who is starting*/
	srand(time(0));   // Initialization.
	int player = rand() % 2 + 1;
	printf("Playing noughts and crosses. Player %d starts.\n", player);
	
	/*The game starts*/
	switch (player)
	{
	case 1:
		/*Game if player 1 begins*/
		while (victory == 0)
		{
			printing_board(grid);
			player1_move(grid);
			moves++;
			victory = game_over(grid, 1);
			if (victory != 0)
				break;
			/*If 9 moves have already been made without succes the game is over in draw*/
			if (moves == 9)
				break;
			printing_board(grid);
			player2_move(grid);
			moves++;
			victory = game_over(grid, 2);
			if (victory != 0)
				break;
		}
		break;
	case 2:
		/*Game if player 2 begins*/
		while (victory == 0)
		{
			printing_board(grid);
			player2_move(grid);
			moves++;
			victory = game_over(grid, 2);
			if (victory != 0)
				break;
			/*If 9 moves have already been made without succes the game is over in draw*/
			if (moves == 9)
				break;
			printing_board(grid);
			player1_move(grid);
			moves++;
			victory = game_over(grid, 1);
			if (victory != 0)
				break;
		}
		break;
	default:
		return EXIT_FAILURE;
	}
	printf("The game is over.\n");
	printing_board(grid);
	if (victory == 0)
	{
		printf("There is a draw.\n");
	}
	else
	{
		printf("The winner is Player %d", victory);
	}
	return EXIT_SUCCESS;
}

