#include<stdio.h>
void check_finish(int i, int j)
{
	if(i ==8 && j ==8)
	{
		cnt++;
		printmap();
		return;
	}
	else
	{
		increment(&i, &j);
		while (readonlySudoku[i][j]>0)
		{
			if (i == 8 && j == 8)
			{
				printmap();
				cnt++;
				return;
			}
			increment(&i, &j);
		}
		for (int v = 1; v <= 9; v++)
		{
			sudoku[i][j] = v;
			check_sudoku(i, j);
		}
		sudoku[i][j] = 0;
		return;
	}
}
