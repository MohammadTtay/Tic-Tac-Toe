#include "firstpage.h"

#include "ui_firstpage.h"

#include<QMessageBox>

#include<QFile>

#include<QFileInfo>

#include<QTextStream>

FirstPage::FirstPage(QWidget * parent): QMainWindow(parent), ui(new Ui::FirstPage) {
    ui -> setupUi(this);
    this -> setWindowTitle("TIC TAC TOE");
}

FirstPage::~FirstPage() {
    delete ui;
}

void FirstPage::on_EnterButton_clicked() {
    QString FirstPlayer = ui -> PlineEdit -> text();
    QString SecondPlayer = ui -> P2_lineEdit -> text();

    if (FirstPlayer.isEmpty() || SecondPlayer.isEmpty()) {///////////////////////Check If One Of The Line Edits Is Empty
        if (FirstPlayer.isEmpty() && SecondPlayer.isEmpty()) {
            QMessageBox::warning(this, " ", "Please Enter The Name Players");

        } else if (FirstPlayer.isEmpty()) {
            QMessageBox::warning(this, " ", "Please Enter The Name Of First Player");

        } else if (SecondPlayer.isEmpty()) {
            QMessageBox::warning(this, " ", "Please Enter The Name Of Second Player");

        }

    } else {
        QFile file("players.txt");
        QTextStream in ( & file);
        QTextStream out( & file);
        out.setCodec("UTF-8"); in .setCodec("UTF-8");
        bool flag1 = true;
        bool flag2 = true;
        QString Player;
        QString Win, Draw, Lose;
        if (QFileInfo::exists("players.txt")) {
            file.open(QFile::ReadWrite | QFile::Text);
            do {
                Player = in .readLine();
                Win = in .readLine();
                Draw = in .readLine();
                Lose = in .readLine();

                if (Player == FirstPlayer) {
                    flag1 = false;
                }
                if (Player == SecondPlayer) {
                    flag2 = false;
                }

            } while (!Player.isNull());
            if (flag1 == true) {
                out << "\n" << FirstPlayer << "\n0\n0\n0";
            }
            if (flag2 == true) {
                out << "\n" << SecondPlayer << "\n0\n0\n0";

            }
            QMessageBox::information(this, " ", "Welcome To The TIC TAC TOE");
            ui -> PlineEdit -> clear();
            ui -> P2_lineEdit -> clear();
            file.flush();
            file.close();
        } else {
            file.open(QFile::ReadWrite | QFile::Text);
            out << FirstPlayer << "\n0\n0\n0\n" << SecondPlayer << "\n0\n0\n0\n";
            QMessageBox::information(this, " ", "Welcome To The TIC TAC TOE");
            ui -> PlineEdit -> clear();
            ui -> P2_lineEdit -> clear();

            file.flush();
            file.close();
        }
        this -> hide();//////////////////////////////////////////////////Opening The Game
        gamepage = new GamePage(this, FirstPlayer, SecondPlayer);
        gamepage -> show();
    }

}
