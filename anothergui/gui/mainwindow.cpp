#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QAction>
#include <QtGui>
#include <QLabel>
#include <GL/gl.h>
#include <stdio.h>

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
    ui->textEdit_1->setText(QString::number(readonlySudoku[0][0]));
    ui->textEdit_2->setText(QString::number(readonlySudoku[0][1]));
    ui->textEdit_3->setText(QString::number(readonlySudoku[0][2]));
    ui->textEdit_4->setText(QString::number(readonlySudoku[0][3]));
    ui->textEdit_5->setText(QString::number(readonlySudoku[0][4]));
    ui->textEdit_6->setText(QString::number(readonlySudoku[0][5]));
    ui->textEdit_7->setText(QString::number(readonlySudoku[0][6]));
    ui->textEdit_8->setText(QString::number(readonlySudoku[0][7]));
    ui->textEdit_9->setText(QString::number(readonlySudoku[0][8]));

    ui->textEdit_10->setText(QString::number(readonlySudoku[1][0]));
    ui->textEdit_11->setText(QString::number(readonlySudoku[1][1]));
    ui->textEdit_12->setText(QString::number(readonlySudoku[1][2]));
    ui->textEdit_13->setText(QString::number(readonlySudoku[1][3]));
    ui->textEdit_14->setText(QString::number(readonlySudoku[1][4]));
    ui->textEdit_15->setText(QString::number(readonlySudoku[1][5]));
    ui->textEdit_16->setText(QString::number(readonlySudoku[1][6]));
    ui->textEdit_17->setText(QString::number(readonlySudoku[1][7]));
    ui->textEdit_18->setText(QString::number(readonlySudoku[1][8]));

    ui->textEdit_19->setText(QString::number(readonlySudoku[2][0]));
    ui->textEdit_20->setText(QString::number(readonlySudoku[2][1]));
    ui->textEdit_21->setText(QString::number(readonlySudoku[2][2]));
    ui->textEdit_22->setText(QString::number(readonlySudoku[2][3]));
    ui->textEdit_23->setText(QString::number(readonlySudoku[2][4]));
    ui->textEdit_24->setText(QString::number(readonlySudoku[2][5]));
    ui->textEdit_25->setText(QString::number(readonlySudoku[2][6]));
    ui->textEdit_26->setText(QString::number(readonlySudoku[2][7]));
    ui->textEdit_27->setText(QString::number(readonlySudoku[2][8]));

    ui->textEdit_28->setText(QString::number(readonlySudoku[3][0]));
    ui->textEdit_29->setText(QString::number(readonlySudoku[3][1]));
    ui->textEdit_30->setText(QString::number(readonlySudoku[3][2]));
    ui->textEdit_31->setText(QString::number(readonlySudoku[3][3]));
    ui->textEdit_32->setText(QString::number(readonlySudoku[3][4]));
    ui->textEdit_33->setText(QString::number(readonlySudoku[3][5]));
    ui->textEdit_34->setText(QString::number(readonlySudoku[3][6]));
    ui->textEdit_35->setText(QString::number(readonlySudoku[3][7]));
    ui->textEdit_36->setText(QString::number(readonlySudoku[3][8]));

    ui->textEdit_37->setText(QString::number(readonlySudoku[4][0]));
    ui->textEdit_38->setText(QString::number(readonlySudoku[4][1]));
    ui->textEdit_39->setText(QString::number(readonlySudoku[4][2]));
    ui->textEdit_40->setText(QString::number(readonlySudoku[4][3]));
    ui->textEdit_41->setText(QString::number(readonlySudoku[4][4]));
    ui->textEdit_42->setText(QString::number(readonlySudoku[4][5]));
    ui->textEdit_43->setText(QString::number(readonlySudoku[4][6]));
    ui->textEdit_44->setText(QString::number(readonlySudoku[4][7]));
    ui->textEdit_45->setText(QString::number(readonlySudoku[4][8]));

    ui->textEdit_46->setText(QString::number(readonlySudoku[5][0]));
    ui->textEdit_47->setText(QString::number(readonlySudoku[5][1]));
    ui->textEdit_48->setText(QString::number(readonlySudoku[5][2]));
    ui->textEdit_49->setText(QString::number(readonlySudoku[5][3]));
    ui->textEdit_50->setText(QString::number(readonlySudoku[5][4]));
    ui->textEdit_51->setText(QString::number(readonlySudoku[5][5]));
    ui->textEdit_52->setText(QString::number(readonlySudoku[5][6]));
    ui->textEdit_53->setText(QString::number(readonlySudoku[5][7]));
    ui->textEdit_54->setText(QString::number(readonlySudoku[5][8]));

    ui->textEdit_55->setText(QString::number(readonlySudoku[6][0]));
    ui->textEdit_56->setText(QString::number(readonlySudoku[6][1]));
    ui->textEdit_57->setText(QString::number(readonlySudoku[6][2]));
    ui->textEdit_58->setText(QString::number(readonlySudoku[6][3]));
    ui->textEdit_59->setText(QString::number(readonlySudoku[6][4]));
    ui->textEdit_60->setText(QString::number(readonlySudoku[6][5]));
    ui->textEdit_61->setText(QString::number(readonlySudoku[6][6]));
    ui->textEdit_62->setText(QString::number(readonlySudoku[6][7]));
    ui->textEdit_63->setText(QString::number(readonlySudoku[6][8]));

    ui->textEdit_64->setText(QString::number(readonlySudoku[7][0]));
    ui->textEdit_65->setText(QString::number(readonlySudoku[7][1]));
    ui->textEdit_66->setText(QString::number(readonlySudoku[7][2]));
    ui->textEdit_67->setText(QString::number(readonlySudoku[7][3]));
    ui->textEdit_68->setText(QString::number(readonlySudoku[7][4]));
    ui->textEdit_69->setText(QString::number(readonlySudoku[7][5]));
    ui->textEdit_70->setText(QString::number(readonlySudoku[7][6]));
    ui->textEdit_71->setText(QString::number(readonlySudoku[7][7]));
    ui->textEdit_72->setText(QString::number(readonlySudoku[7][8]));

    ui->textEdit_73->setText(QString::number(readonlySudoku[8][0]));
    ui->textEdit_74->setText(QString::number(readonlySudoku[8][1]));
    ui->textEdit_75->setText(QString::number(readonlySudoku[8][2]));
    ui->textEdit_76->setText(QString::number(readonlySudoku[8][3]));
    ui->textEdit_77->setText(QString::number(readonlySudoku[8][4]));
    ui->textEdit_78->setText(QString::number(readonlySudoku[8][5]));
    ui->textEdit_79->setText(QString::number(readonlySudoku[8][6]));
    ui->textEdit_80->setText(QString::number(readonlySudoku[8][7]));
    ui->textEdit_81->setText(QString::number(readonlySudoku[8][8]));
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
