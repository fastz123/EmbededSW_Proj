#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QAction>
#include <QtGui>
#include <QLabel>
#include <GL/gl.h>
#include <stdio.h>

int sudoku[9][9] =
{ 0, };

int Sudoku[9][9]=
{0,};

int readonlySudoku[9][9] =
{ 0, };

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

void printmap2()
{
    for (int i = 0; i<9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", readonlySudoku[i][j]);
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
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int i = 0;
    int j = 0;
    //printf("before solve sudoku\n");
    //printmap();
    //printf("\n");
    //printf("after solve sudoku\n");
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

    ui->textEdit_1->setText(QString::number(Sudoku[0][0]));
    ui->textEdit_2->setText(QString::number(Sudoku[0][1]));
    ui->textEdit_3->setText(QString::number(Sudoku[0][2]));
    ui->textEdit_4->setText(QString::number(Sudoku[0][3]));
    ui->textEdit_5->setText(QString::number(Sudoku[0][4]));
    ui->textEdit_6->setText(QString::number(Sudoku[0][5]));
    ui->textEdit_7->setText(QString::number(Sudoku[0][6]));
    ui->textEdit_8->setText(QString::number(Sudoku[0][7]));
    ui->textEdit_9->setText(QString::number(Sudoku[0][8]));

    ui->textEdit_10->setText(QString::number(Sudoku[1][0]));
    ui->textEdit_11->setText(QString::number(Sudoku[1][1]));
    ui->textEdit_12->setText(QString::number(Sudoku[1][2]));
    ui->textEdit_13->setText(QString::number(Sudoku[1][3]));
    ui->textEdit_14->setText(QString::number(Sudoku[1][4]));
    ui->textEdit_15->setText(QString::number(Sudoku[1][5]));
    ui->textEdit_16->setText(QString::number(Sudoku[1][6]));
    ui->textEdit_17->setText(QString::number(Sudoku[1][7]));
    ui->textEdit_18->setText(QString::number(Sudoku[1][8]));

    ui->textEdit_19->setText(QString::number(Sudoku[2][0]));
    ui->textEdit_20->setText(QString::number(Sudoku[2][1]));
    ui->textEdit_21->setText(QString::number(Sudoku[2][2]));
    ui->textEdit_22->setText(QString::number(Sudoku[2][3]));
    ui->textEdit_23->setText(QString::number(Sudoku[2][4]));
    ui->textEdit_24->setText(QString::number(Sudoku[2][5]));
    ui->textEdit_25->setText(QString::number(Sudoku[2][6]));
    ui->textEdit_26->setText(QString::number(Sudoku[2][7]));
    ui->textEdit_27->setText(QString::number(Sudoku[2][8]));
    ui->textEdit_28->setText(QString::number(Sudoku[3][0]));
    ui->textEdit_29->setText(QString::number(Sudoku[3][1]));
    ui->textEdit_30->setText(QString::number(Sudoku[3][2]));
    ui->textEdit_31->setText(QString::number(Sudoku[3][3]));
    ui->textEdit_32->setText(QString::number(Sudoku[3][4]));
    ui->textEdit_33->setText(QString::number(Sudoku[3][5]));
    ui->textEdit_34->setText(QString::number(Sudoku[3][6]));
    ui->textEdit_35->setText(QString::number(Sudoku[3][7]));
    ui->textEdit_36->setText(QString::number(Sudoku[3][8]));

    ui->textEdit_37->setText(QString::number(Sudoku[4][0]));
    ui->textEdit_38->setText(QString::number(Sudoku[4][1]));
    ui->textEdit_39->setText(QString::number(Sudoku[4][2]));
    ui->textEdit_40->setText(QString::number(Sudoku[4][3]));
    ui->textEdit_41->setText(QString::number(Sudoku[4][4]));
    ui->textEdit_42->setText(QString::number(Sudoku[4][5]));
    ui->textEdit_43->setText(QString::number(Sudoku[4][6]));
    ui->textEdit_44->setText(QString::number(Sudoku[4][7]));
    ui->textEdit_45->setText(QString::number(Sudoku[4][8]));
    ui->textEdit_46->setText(QString::number(Sudoku[5][0]));
    ui->textEdit_47->setText(QString::number(Sudoku[5][1]));
    ui->textEdit_48->setText(QString::number(Sudoku[5][2]));
    ui->textEdit_49->setText(QString::number(Sudoku[5][3]));
    ui->textEdit_50->setText(QString::number(Sudoku[5][4]));
    ui->textEdit_51->setText(QString::number(Sudoku[5][5]));
    ui->textEdit_52->setText(QString::number(Sudoku[5][6]));
    ui->textEdit_53->setText(QString::number(Sudoku[5][7]));
    ui->textEdit_54->setText(QString::number(Sudoku[5][8]));

    ui->textEdit_55->setText(QString::number(Sudoku[6][0]));
    ui->textEdit_56->setText(QString::number(Sudoku[6][1]));
    ui->textEdit_57->setText(QString::number(Sudoku[6][2]));
    ui->textEdit_58->setText(QString::number(Sudoku[6][3]));
    ui->textEdit_59->setText(QString::number(Sudoku[6][4]));
    ui->textEdit_60->setText(QString::number(Sudoku[6][5]));
    ui->textEdit_61->setText(QString::number(Sudoku[6][6]));
    ui->textEdit_62->setText(QString::number(Sudoku[6][7]));
    ui->textEdit_63->setText(QString::number(Sudoku[6][8]));

    ui->textEdit_64->setText(QString::number(Sudoku[7][0]));
    ui->textEdit_65->setText(QString::number(Sudoku[7][1]));
    ui->textEdit_66->setText(QString::number(Sudoku[7][2]));
    ui->textEdit_67->setText(QString::number(Sudoku[7][3]));
    ui->textEdit_68->setText(QString::number(Sudoku[7][4]));
    ui->textEdit_69->setText(QString::number(Sudoku[7][5]));
    ui->textEdit_70->setText(QString::number(Sudoku[7][6]));
    ui->textEdit_71->setText(QString::number(Sudoku[7][7]));
    ui->textEdit_72->setText(QString::number(Sudoku[7][8]));

    ui->textEdit_73->setText(QString::number(Sudoku[8][0]));
    ui->textEdit_74->setText(QString::number(Sudoku[8][1]));
    ui->textEdit_75->setText(QString::number(Sudoku[8][2]));
    ui->textEdit_76->setText(QString::number(Sudoku[8][3]));
    ui->textEdit_77->setText(QString::number(Sudoku[8][4]));
    ui->textEdit_78->setText(QString::number(Sudoku[8][5]));
    ui->textEdit_79->setText(QString::number(Sudoku[8][6]));
    ui->textEdit_80->setText(QString::number(Sudoku[8][7]));
    ui->textEdit_81->setText(QString::number(Sudoku[8][8]));
    //printmap();
}

void MainWindow::on_pushButton_2_clicked()
{
    readonlySudoku[0][0] = ui->lineEdit->text().toInt();
    readonlySudoku[0][1] = ui->lineEdit_2->text().toInt();
    readonlySudoku[0][2] = ui->lineEdit_3->text().toInt();
    readonlySudoku[0][3] = ui->lineEdit_4->text().toInt();
    readonlySudoku[0][4] = ui->lineEdit_5->text().toInt();
    readonlySudoku[0][5] = ui->lineEdit_6->text().toInt();
    readonlySudoku[0][6] = ui->lineEdit_7->text().toInt();
    readonlySudoku[0][7] = ui->lineEdit_8->text().toInt();
    readonlySudoku[0][8] = ui->lineEdit_9->text().toInt();

    readonlySudoku[1][0] = ui->lineEdit_10->text().toInt();
    readonlySudoku[1][1] = ui->lineEdit_11->text().toInt();
    readonlySudoku[1][2] = ui->lineEdit_12->text().toInt();
    readonlySudoku[1][3] = ui->lineEdit_13->text().toInt();
    readonlySudoku[1][4] = ui->lineEdit_14->text().toInt();
    readonlySudoku[1][5] = ui->lineEdit_15->text().toInt();
    readonlySudoku[1][6] = ui->lineEdit_16->text().toInt();
    readonlySudoku[1][7] = ui->lineEdit_17->text().toInt();
    readonlySudoku[1][8] = ui->lineEdit_18->text().toInt();

    readonlySudoku[2][0] = ui->lineEdit_19->text().toInt();
    readonlySudoku[2][1] = ui->lineEdit_20->text().toInt();
    readonlySudoku[2][2] = ui->lineEdit_21->text().toInt();
    readonlySudoku[2][3] = ui->lineEdit_22->text().toInt();
    readonlySudoku[2][4] = ui->lineEdit_23->text().toInt();
    readonlySudoku[2][5] = ui->lineEdit_24->text().toInt();
    readonlySudoku[2][6] = ui->lineEdit_25->text().toInt();
    readonlySudoku[2][7] = ui->lineEdit_26->text().toInt();
    readonlySudoku[2][8] = ui->lineEdit_27->text().toInt();

    readonlySudoku[3][0] = ui->lineEdit_28->text().toInt();
    readonlySudoku[3][1] = ui->lineEdit_29->text().toInt();
    readonlySudoku[3][2] = ui->lineEdit_30->text().toInt();
    readonlySudoku[3][3] = ui->lineEdit_31->text().toInt();
    readonlySudoku[3][4] = ui->lineEdit_32->text().toInt();
    readonlySudoku[3][5] = ui->lineEdit_33->text().toInt();
    readonlySudoku[3][6] = ui->lineEdit_34->text().toInt();
    readonlySudoku[3][7] = ui->lineEdit_35->text().toInt();
    readonlySudoku[3][8] = ui->lineEdit_36->text().toInt();

    readonlySudoku[4][0] = ui->lineEdit_37->text().toInt();
    readonlySudoku[4][1] = ui->lineEdit_38->text().toInt();
    readonlySudoku[4][2] = ui->lineEdit_39->text().toInt();
    readonlySudoku[4][3] = ui->lineEdit_40->text().toInt();
    readonlySudoku[4][4] = ui->lineEdit_41->text().toInt();
    readonlySudoku[4][5] = ui->lineEdit_42->text().toInt();
    readonlySudoku[4][6] = ui->lineEdit_43->text().toInt();
    readonlySudoku[4][7] = ui->lineEdit_44->text().toInt();
    readonlySudoku[4][8] = ui->lineEdit_45->text().toInt();

    readonlySudoku[5][0] = ui->lineEdit_46->text().toInt();
    readonlySudoku[5][1] = ui->lineEdit_47->text().toInt();
    readonlySudoku[5][2] = ui->lineEdit_48->text().toInt();
    readonlySudoku[5][3] = ui->lineEdit_49->text().toInt();
    readonlySudoku[5][4] = ui->lineEdit_50->text().toInt();
    readonlySudoku[5][5] = ui->lineEdit_51->text().toInt();
    readonlySudoku[5][6] = ui->lineEdit_52->text().toInt();
    readonlySudoku[5][7] = ui->lineEdit_53->text().toInt();
    readonlySudoku[5][8] = ui->lineEdit_54->text().toInt();

    readonlySudoku[6][0] = ui->lineEdit_55->text().toInt();
    readonlySudoku[6][1] = ui->lineEdit_56->text().toInt();
    readonlySudoku[6][2] = ui->lineEdit_57->text().toInt();
    readonlySudoku[6][3] = ui->lineEdit_58->text().toInt();
    readonlySudoku[6][4] = ui->lineEdit_59->text().toInt();
    readonlySudoku[6][5] = ui->lineEdit_60->text().toInt();
    readonlySudoku[6][6] = ui->lineEdit_61->text().toInt();
    readonlySudoku[6][7] = ui->lineEdit_62->text().toInt();
    readonlySudoku[6][8] = ui->lineEdit_63->text().toInt();

    readonlySudoku[7][0] = ui->lineEdit_64->text().toInt();
    readonlySudoku[7][1] = ui->lineEdit_65->text().toInt();
    readonlySudoku[7][2] = ui->lineEdit_66->text().toInt();
    readonlySudoku[7][3] = ui->lineEdit_67->text().toInt();
    readonlySudoku[7][4] = ui->lineEdit_68->text().toInt();
    readonlySudoku[7][5] = ui->lineEdit_69->text().toInt();
    readonlySudoku[7][6] = ui->lineEdit_70->text().toInt();
    readonlySudoku[7][7] = ui->lineEdit_71->text().toInt();
    readonlySudoku[7][8] = ui->lineEdit_72->text().toInt();

    readonlySudoku[8][0] = ui->lineEdit_73->text().toInt();
    readonlySudoku[8][1] = ui->lineEdit_74->text().toInt();
    readonlySudoku[8][2] = ui->lineEdit_75->text().toInt();
    readonlySudoku[8][3] = ui->lineEdit_76->text().toInt();
    readonlySudoku[8][4] = ui->lineEdit_77->text().toInt();
    readonlySudoku[8][5] = ui->lineEdit_78->text().toInt();
    readonlySudoku[8][6] = ui->lineEdit_79->text().toInt();
    readonlySudoku[8][7] = ui->lineEdit_80->text().toInt();
    readonlySudoku[8][8] = ui->lineEdit_81->text().toInt();

    memcpy(sudoku,readonlySudoku,sizeof(readonlySudoku));
   //printmap2();
   //printf("\n");
}

void MainWindow::on_sudokuclearbtn_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_19->setText("");
    ui->lineEdit_20->setText("");
    ui->lineEdit_21->setText("");
    ui->lineEdit_22->setText("");
    ui->lineEdit_23->setText("");
    ui->lineEdit_24->setText("");
    ui->lineEdit_25->setText("");
    ui->lineEdit_26->setText("");
    ui->lineEdit_27->setText("");
    ui->lineEdit_28->setText("");
    ui->lineEdit_29->setText("");
    ui->lineEdit_30->setText("");
    ui->lineEdit_31->setText("");
    ui->lineEdit_32->setText("");
    ui->lineEdit_33->setText("");
    ui->lineEdit_34->setText("");
    ui->lineEdit_35->setText("");
    ui->lineEdit_36->setText("");
    ui->lineEdit_37->setText("");
    ui->lineEdit_38->setText("");
    ui->lineEdit_39->setText("");
    ui->lineEdit_40->setText("");
    ui->lineEdit_41->setText("");
    ui->lineEdit_42->setText("");
    ui->lineEdit_43->setText("");
    ui->lineEdit_44->setText("");
    ui->lineEdit_45->setText("");
    ui->lineEdit_46->setText("");
    ui->lineEdit_47->setText("");
    ui->lineEdit_48->setText("");
    ui->lineEdit_49->setText("");
    ui->lineEdit_50->setText("");
    ui->lineEdit_51->setText("");
    ui->lineEdit_52->setText("");
    ui->lineEdit_53->setText("");
    ui->lineEdit_54->setText("");
    ui->lineEdit_55->setText("");
    ui->lineEdit_56->setText("");
    ui->lineEdit_57->setText("");
    ui->lineEdit_58->setText("");
    ui->lineEdit_59->setText("");
    ui->lineEdit_60->setText("");
    ui->lineEdit_61->setText("");
    ui->lineEdit_62->setText("");
    ui->lineEdit_63->setText("");
    ui->lineEdit_64->setText("");
    ui->lineEdit_65->setText("");
    ui->lineEdit_66->setText("");
    ui->lineEdit_67->setText("");
    ui->lineEdit_68->setText("");
    ui->lineEdit_69->setText("");
    ui->lineEdit_70->setText("");
    ui->lineEdit_71->setText("");
    ui->lineEdit_72->setText("");
    ui->lineEdit_73->setText("");
    ui->lineEdit_74->setText("");
    ui->lineEdit_75->setText("");
    ui->lineEdit_76->setText("");
    ui->lineEdit_77->setText("");
    ui->lineEdit_78->setText("");
    ui->lineEdit_79->setText("");
    ui->lineEdit_80->setText("");
    ui->lineEdit_81->setText("");
}

void MainWindow::on_ansclearbtn_clicked()
{
    ui->textEdit_1->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
    ui->textEdit_4->setText("");
    ui->textEdit_5->setText("");
    ui->textEdit_6->setText("");
    ui->textEdit_7->setText("");
    ui->textEdit_8->setText("");
    ui->textEdit_9->setText("");
    ui->textEdit_10->setText("");
    ui->textEdit_11->setText("");
    ui->textEdit_12->setText("");
    ui->textEdit_13->setText("");
    ui->textEdit_14->setText("");
    ui->textEdit_15->setText("");
    ui->textEdit_16->setText("");
    ui->textEdit_17->setText("");
    ui->textEdit_18->setText("");
    ui->textEdit_19->setText("");
    ui->textEdit_20->setText("");
    ui->textEdit_21->setText("");
    ui->textEdit_22->setText("");
    ui->textEdit_23->setText("");
    ui->textEdit_24->setText("");
    ui->textEdit_25->setText("");
    ui->textEdit_26->setText("");
    ui->textEdit_27->setText("");
    ui->textEdit_28->setText("");
    ui->textEdit_29->setText("");
    ui->textEdit_30->setText("");
    ui->textEdit_31->setText("");
    ui->textEdit_32->setText("");
    ui->textEdit_33->setText("");
    ui->textEdit_34->setText("");
    ui->textEdit_35->setText("");
    ui->textEdit_36->setText("");
    ui->textEdit_37->setText("");
    ui->textEdit_38->setText("");
    ui->textEdit_39->setText("");
    ui->textEdit_40->setText("");
    ui->textEdit_41->setText("");
    ui->textEdit_42->setText("");
    ui->textEdit_43->setText("");
    ui->textEdit_44->setText("");
    ui->textEdit_45->setText("");
    ui->textEdit_46->setText("");
    ui->textEdit_47->setText("");
    ui->textEdit_48->setText("");
    ui->textEdit_49->setText("");
    ui->textEdit_50->setText("");
    ui->textEdit_51->setText("");
    ui->textEdit_52->setText("");
    ui->textEdit_53->setText("");
    ui->textEdit_54->setText("");
    ui->textEdit_55->setText("");
    ui->textEdit_56->setText("");
    ui->textEdit_57->setText("");
    ui->textEdit_58->setText("");
    ui->textEdit_59->setText("");
    ui->textEdit_60->setText("");
    ui->textEdit_61->setText("");
    ui->textEdit_62->setText("");
    ui->textEdit_63->setText("");
    ui->textEdit_64->setText("");
    ui->textEdit_65->setText("");
    ui->textEdit_66->setText("");
    ui->textEdit_67->setText("");
    ui->textEdit_68->setText("");
    ui->textEdit_69->setText("");
    ui->textEdit_70->setText("");
    ui->textEdit_71->setText("");
    ui->textEdit_72->setText("");
    ui->textEdit_73->setText("");
    ui->textEdit_74->setText("");
    ui->textEdit_75->setText("");
    ui->textEdit_76->setText("");
    ui->textEdit_77->setText("");
    ui->textEdit_78->setText("");
    ui->textEdit_79->setText("");
    ui->textEdit_80->setText("");
    ui->textEdit_81->setText("");
}
