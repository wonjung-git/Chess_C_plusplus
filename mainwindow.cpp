#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "piece.h"
#include "board.h"
#include "gamemanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    //보드 판 연결
    char col[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char row[8] = {'8', '7', '6', '5', '4', '3', '2', '1'};

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            QString name = QString("board_") + QString(col[j]) + QString(row[i]);
            boardButtons[i][j] = findChild<QPushButton*>(name);
            qDebug() << name << (boardButtons[i][j] != nullptr ? "OK" : "NULL");
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawBoard(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            Piece *piece = gamemanager.getBoard().getPiece(i, j);
            if(piece != nullptr)
                boardButtons[i][j]->setText(QString(piece->getSymbol()));
            else boardButtons[i][j]->setText(QString(""));
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    gamemanager.reset_game();
    drawBoard();
}



