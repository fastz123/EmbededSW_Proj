#include<stdio.h>
#include<string.h>
#include"sudokudata.h"
void check_sudoku(int i, int j)
{
    //int failed = 0;
    for (int k = 0; k < 9; k++)
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

    for (int k = 0; k < 9; k++)
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

    int r = (i / 3) * 3;
    int c = (j / 3) * 3;
    for (int x = r; x<r + 3; x++)
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
    if (i == 8 && j == 8)
    {
        cnt++;
        //printmap();
        memcpy(Sudoku,sudoku,sizeof(sudoku));
        return;
    }
    else
    {
        increment(&i, &j);
        while (readonlySudoku[i][j]>0)
        {
            if (i == 8 && j == 8)
            {
                //printmap();
                memcpy(Sudoku,sudoku,sizeof(sudoku));
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
