#pragma once

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3

/*Functions declaration*/
void printing_board(char board[MAX][MAX]);
void player_move(char board[MAX][MAX], int player);
int player_input(char board[MAX][MAX], int player);
int game_over(char board[MAX][MAX], int player);
