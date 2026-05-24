#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "gamemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void drawBoard();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    GameManager gamemanager;

    //보드 버튼들 저장하는 2차원 배열
    QPushButton* boardButtons[8][8];
};
#endif // MAINWINDOW_H
