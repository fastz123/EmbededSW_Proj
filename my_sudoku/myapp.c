#include<stdio.h>


void main()
{
	int i = 0;
	int j = 0;
	printf("before solve sudoku\n");
	printmap();
	printf("\n");
	printf("after solve sudoku\n");
	while (readonlySudoku[i][j]>0)
	{
		increment(&i, &j);
	}
	//printf("위 스도쿠는 정답이 %d개입니다.\n", cnt);
	//printmap();
}
