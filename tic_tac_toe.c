// Write a program that implements a simple text-based Tic-Tac-Toe game for two players.

#include <stdio.h>

void displayBoard(char board[3][3]){
	printf("\n  %c | %c | %c \n ---+---+---\n  %c | %c | %c \n ---+---+---\n  %c | %c | %c \n",
		board[0][0], board[0][1], board[0][2],
		board[1][0], board[1][1], board[1][2],
		board[2][0], board[2][1], board[2][2]);
}

int checkWinner(char board[3][3], char mark, int turn)
{

	// Check Rows & Columns
	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) 
		|| (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
		{
			if (turn == 0)
				{
					printf("\n");
					displayBoard(board);
					printf("\n");
					printf("Player 1 Wins!\n");
					return 1;
				}
				else
				{
					printf("\n");
					displayBoard(board);
					printf("\n");
					printf("Player 2 Wins!\n");
					return 1;
				}
		}
		// Check Diagonals

		if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) || 
		(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
		{
			if (turn == 0)
			{
				printf("\n");
				displayBoard(board);
				printf("\n");
				printf("Player 1 Wins!\n");
				return 1;
			}
			else
			{
				printf("\n");
				displayBoard(board);
				printf("\n");
				printf("Player 2 Wins!\n");
				return 1;
			}
		}
	}
	return 0;
}

void tictactoe()
{
	int turn = 0; // 0 for Player 1, 1 for Player 2
	char board[3][3] = {{'1', '2', '3'},
						{'4', '5', '6'},
						{'7', '8', '9'}};

	int move;

	// Loop for 9 turns (maximum moves in Tic-Tac-Toe)
	for (int i = 0; i < 9; i++)
	{
		// Display the board before each turn
		displayBoard(board);

		// Alternating prompt
		if (turn == 0)
		{
			printf("\nPlayer 1 (X), enter your move (1-9): ");
		}
		else
		{
			printf("\nPlayer 2 (O), enter your move (1-9): ");
		}

		// Get user input while validating it
		// scanf returns 0 if an integer won't be entered, so if scanf != 1, that means its not an integer in the first place
		// Next if its a number,it stores the value in move and it checks if its in the range 1 to 9, if not then print error message and continue,
		if (scanf("%d", &move) != 1 || move < 1 || move > 9) {
			// all of this only happens if move is invalid otherwise move simple stores the value, and no error message is given, no buffer clearing and simple the program moves forward
			printf("Invalid input. Please enter a number between 1 and 9.\n"); 
			while (getchar() != '\n'); // Clear input buffer
			i--;
			continue;
		}

		// Mark the board
		char mark = (turn == 0) ? 'X' : 'O';
		int row = (move - 1) / 3;
		int col = (move - 1) % 3;

		if (board[row][col] == 'X' || board[row][col] == 'O')
		{
			printf("Spot already taken. Choose another.\n");
			i--;
			continue;
		}

		board[row][col] = mark;

		if (checkWinner(board, mark, turn))
		{
			return; // Stop the game
		}

		// Switch turn
		turn = 1 - turn;
	}

	displayBoard(board);
	printf("Its a draw!\n");

}

int main()
{
	int condition;
	do
	{
		tictactoe();
		printf("Do you want to continue? Yes-1, No-0\n");
		scanf("%d",&condition);
	
	} while (condition == 1);
	
	return 0;
}