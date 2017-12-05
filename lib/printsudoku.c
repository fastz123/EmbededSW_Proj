#include<stdio.h>
#include"sudokudata.h"
void print_sudoku(int i,int j)
{
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", sudoku[i][j]);
			if (j == 8)
			{
				printf("\n");
			}
		}
	}
	return;
}
