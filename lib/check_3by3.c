int check_3by3()
{
	int r = (i / 3) * 3;// 같은칸의 시작 x좌표
	int c = (j / 3) * 3;// 같은칸의 시작 y좌표
	for (int x = r; x<r + 3; x++)					//칸검사
	{
		for (int y = c; y<c + 3; y++)
		{
			if (x == i&&y == j)
			{
				continue;
			}
			else
			{
				if (sudoku[i][j] == sudoku[x][y])
				{
					//failed = 1;
					return;
				}
			}
		}
	}
]
