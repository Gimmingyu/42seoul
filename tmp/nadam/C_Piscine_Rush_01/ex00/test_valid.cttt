#include <stdio.h>

int is_valid(int **board, int **inputs);
int **malloc_arrs(void);
void print_ints(int **ints);

int main(void)
{
	int **board = malloc_arrs();
	int **inputs = malloc_arrs();

	char t[] = "1234234134124123";
	char tt[] = "4321122243211222";

	int count = 0;
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			board[i][j] = t[count] - '0';
			count++;
		}
	}
	count = 0;
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			inputs[i][j] = tt[count] - '0';
			count++;
		}
	}

	print_ints(board);
	printf("\n");
	print_ints(inputs);
	printf("\n");

	printf("%d \n", is_valid(board, inputs));
	return 0;
}
