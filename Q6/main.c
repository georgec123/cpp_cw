#include "header.h"

int main(void)
{
	/*Initialise the board*/
	char grid[MAX][MAX] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}};
	
	
	int victory = 0; // Victory represents the state of the game: 0 for draw and i for player i-th victory
	int moves = 0;

	/*Add a random number to decide who is starting*/
	srand(time(0)); // Initialization.
	int player = rand() % 2 + 1;
	printf("Playing noughts and crosses. Player %d starts.\n", player);

	/*The game starts*/
	while (victory == 0 || moves < 9)
	{
		printing_board(grid);
		player_move(grid, player);

		moves++;
		victory = game_over(grid, player);
		player = 3-player; // toggle player
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
