#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QMainWindow>

#include<gamepage.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class FirstPage;
}
QT_END_NAMESPACE

class FirstPage: public QMainWindow {
    Q_OBJECT

public:
    FirstPage(QWidget * parent = nullptr);
    ~FirstPage();

private slots:

    void on_EnterButton_clicked();

private:
    Ui::FirstPage * ui;
    GamePage * gamepage;

};
#endif // FIRSTPAGE_H
