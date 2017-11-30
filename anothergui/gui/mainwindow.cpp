#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QAction>
#include <QtGui>
#include <QLabel>
#include <GL/gl.h>
#include <stdio.h>

int guisudoku[9][9] =
{ 8,0,6,0,0,0,0,3,0,
4,7,0,6,0,2,0,5,1,
0,0,5,0,8,0,0,0,9,
0,0,0,2,1,0,3,0,6,
1,0,0,0,4,0,0,0,5,
9,0,3,0,7,5,0,0,0,
6,0,0,0,2,0,5,0,0,
3,9,0,5,0,8,0,2,4,
0,4,0,0,0,0,1,0,8 };

int sudoku[9][9] =
{ 8,0,6,0,0,0,0,3,0,
4,7,0,6,0,2,0,5,1,
0,0,5,0,8,0,0,0,9,
0,0,0,2,1,0,3,0,6,
1,0,0,0,4,0,0,0,5,
9,0,3,0,7,5,0,0,0,
6,0,0,0,2,0,5,0,0,
3,9,0,5,0,8,0,2,4,
0,4,0,0,0,0,1,0,8 };

int readonlySudoku[9][9] =
{ 8,0,6,0,0,0,0,3,0,
4,7,0,6,0,2,0,5,1,
0,0,5,0,8,0,0,0,9,
0,0,0,2,1,0,3,0,6,
1,0,0,0,4,0,0,0,5,
9,0,3,0,7,5,0,0,0,
6,0,0,0,2,0,5,0,0,
3,9,0,5,0,8,0,2,4,
0,4,0,0,0,0,1,0,8 };


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

void printmap()
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
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit_1->setText(QString::number(guisudoku[0][0]));
    ui->textEdit_2->setText(QString::number(guisudoku[0][1]));
    ui->textEdit_3->setText(QString::number(guisudoku[0][2]));
    ui->textEdit_4->setText(QString::number(guisudoku[0][3]));
    ui->textEdit_5->setText(QString::number(guisudoku[0][4]));
    ui->textEdit_6->setText(QString::number(guisudoku[0][5]));
    ui->textEdit_7->setText(QString::number(guisudoku[0][6]));
    ui->textEdit_8->setText(QString::number(guisudoku[0][7]));
    ui->textEdit_9->setText(QString::number(guisudoku[0][8]));

    ui->textEdit_10->setText(QString::number(guisudoku[1][0]));
    ui->textEdit_11->setText(QString::number(guisudoku[1][1]));
    ui->textEdit_12->setText(QString::number(guisudoku[1][2]));
    ui->textEdit_13->setText(QString::number(guisudoku[1][3]));
    ui->textEdit_14->setText(QString::number(guisudoku[1][4]));
    ui->textEdit_15->setText(QString::number(guisudoku[1][5]));
    ui->textEdit_16->setText(QString::number(guisudoku[1][6]));
    ui->textEdit_17->setText(QString::number(guisudoku[1][7]));
    ui->textEdit_18->setText(QString::number(guisudoku[1][8]));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
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
    for (int v = 1; v <= 9; v++)
    {
        sudoku[i][j] = v;
        check_sudoku(i, j);
    }
    //printf("ans cnt : %d .\n", cnt);
    ui->Answerlabel->setText("answer count : ");
    ui->Answerlabel_2->setText(QString::number(cnt));
}

void MainWindow::on_pushButton_2_clicked()
{

}
