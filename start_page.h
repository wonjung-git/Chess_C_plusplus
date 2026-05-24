#ifndef START_PAGE_H
#define START_PAGE_H

#include <QWidget>

namespace Ui {
class Start_page;
}

class Start_page : public QWidget
{
    Q_OBJECT

public:
    explicit Start_page(QWidget *parent = nullptr);
    ~Start_page();

private:
    Ui::Start_page *ui;
};

#endif // START_PAGE_H
