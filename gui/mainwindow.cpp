#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QLabel>
#include <GL/gl.h>
#include <stdio.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
