#include<stdio.h>
#include<header.h>

void main()
{
	int i = 0;
	int j = 0;
	printf("before solve sudoku\n");
	print_sudoku();
	printf("\n");
	printf("after solve sudoku\n");
	while (readonlySudoku[i][j]>0)
	{
		increment(&i, &j);
	}

	for (int v = 1; v <= 9; v++)
	{
		sudoku[i][j] = v;
		check_sudoku(i, j);
		//sudoku[i][j] = 0;
	}
	//printf("위 스도쿠는 정답이 %d개입니다.\n", cnt);
	//printmap();
}
