#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3

/*Functions declaration*/
void printing_board(char board[MAX][MAX]);
void player1_move(char board[MAX][MAX]);
void player2_move(char board[MAX][MAX]);
int game_over(char board[MAX][MAX], int player);
