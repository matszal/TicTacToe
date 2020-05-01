#include <stdio.h>
#include <stdbool.h>

char matrix[3][3];

void display_matrix();
void get_move();
void get_computer_move();
void init_matrix();
bool is_valid(int, int);
char check_board();

int main()
{
	char done = ' ';
	init_matrix();

	do
	{
		display_matrix();
		get_move();
		done = check_board();
		if (done != ' ') break; // game over
		get_computer_move();
		display_matrix();

	}while (done == ' ');

	display_matrix();
	if (done == 'X')
	{
		printf("You won!\n");
	}
	else
	{
		printf("You LOST!\n");
	}
}

void display_matrix()
{
	int t;
	printf("\n");
	for (t = 0; t < 3; t++)
	{
		printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
		if (t != 2) printf("\n __|___|__\n");
	}
	printf("\n");
}

void get_move()
{
	int x, y;

	printf("\nEnter your coordinates: row col \n");
	while (1)
	{
		scanf_s("%d %d", &x, &y);
		printf("\n");
		x--;
		y--;
		if (is_valid(x, y))
		{
			matrix[x][y] = 'X';
			break;
		}
		else
		{
			printf("Invalid move, try again \n");
			continue;
		}
	}
}

void init_matrix()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

bool is_valid(int x, int y)
{
	return matrix[x][y] == ' ';
}

void get_computer_move()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (matrix[i][j] == ' ') break;
		}
		if (matrix[i][j] == ' ') break;
	}

	if (i * j == 9)
	{
		display_matrix();
		printf("draw\n");
		exit(0);
	}
	else
	{
		matrix[i][j] = 'O';
	}

}

char check_board()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		//check rows
		if (matrix[i][0] == matrix[i][1] &&
			matrix[i][0] == matrix[i][2])
			return matrix[i][0];
	}
	for (i = 0; i < 3; i++)
	{
		//check cols
		if (matrix[0][i] == matrix[1][i] &&
			matrix[0][i] == matrix[2][i])
			return matrix[0][i];
	}
		//check diagnals
		if (matrix[0][0] == matrix[1][1] &&
			matrix[1][1] == matrix[2][2])
			return matrix[0][0];

		//check diagnals
		if (matrix[0][2] == matrix[1][1] &&
			matrix[1][1] == matrix[2][0])
			return matrix[0][2];

		return ' ';
}
