void check_sudoku(int i, int j)
{
	//int failed = 0;
	for (int k = 0; k < 9; k++)	//수직검사
	{
		if (i == k)
		{
			continue;
		}
		else
		{
			if (sudoku[i][j] == sudoku[k][j])
			{
				//failed = 1;
				return;
			}
		}
	}


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
