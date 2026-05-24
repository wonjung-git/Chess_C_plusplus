#include "start_page.h"
#include "ui_start_page.h"

Start_page::Start_page(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Start_page)
{
    ui->setupUi(this);
}

Start_page::~Start_page()
{
    delete ui;
}
