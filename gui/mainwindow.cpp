#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
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

int i,j,k;
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_textEdit_8_textChanged()
{

}
*/
void MainWindow::on_pushButton_clicked()
{
    ui ->Answerlabel->setText("Sudoku Answer!");
}
