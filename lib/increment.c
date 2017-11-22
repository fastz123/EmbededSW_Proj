#include<stdio.h>

int cnt = 0;
void increment(int *i, int*j)
{
	if (*j<8)
	{
		*j = *j + 1;
		return;
	}
	else
	{
		*j = 0;
		*i = *i + 1;
		return;
	}
}

