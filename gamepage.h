#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QMainWindow>
#include<database.h>

namespace Ui {
class GamePage;
}

class GamePage: public QMainWindow {
    Q_OBJECT

public:
    explicit GamePage(QMainWindow *FirstPage,QString FirstPlayer, QString SecondPlayer, QWidget * parent = nullptr);
    ~GamePage();

private slots:

    void on_XButton_clicked();

    void on_OButton_clicked();

    void whosTurnFirst(QString, QString);

    bool CheckwinX();

    bool CheckwinO();

    bool CheckDraw();

    void on_ResetButton_clicked();

    void UpdateFile();

    void on_BackButton_clicked();

private:
    Ui::GamePage * ui;
    QVector<Database> players;
    QMainWindow * Firstpage;
    QString FirstPlayer;
    QString SecondPlayer;
};

#endif // GAMEPAGE_H
