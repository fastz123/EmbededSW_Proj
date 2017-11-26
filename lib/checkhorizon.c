#include<stdio.h>
void check_horizon(int i, int j)
{
	for (int k = 0; k < 9; k++)			//수평검사
	{
		if (j == k)
		{
			continue;
		}
		else
		{
			if (sudoku[i][j] == sudoku[i][k])
			{
				//failed = 1;
				return;
			}
		}
	}
}
