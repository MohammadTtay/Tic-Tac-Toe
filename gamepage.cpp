#include "gamepage.h"

#include "ui_gamepage.h"

#include<time.h>

#include<QDebug>

#include<QMessageBox>

#include<QFile>

#include<QFileInfo>


GamePage::GamePage(QMainWindow * Firstpage, QString FirstPlayer, QString SecondPlayer, QWidget * parent):
      QMainWindow(parent),
      ui(new Ui::GamePage) {
    ui -> setupUi(this);
    this -> Firstpage = Firstpage;

    this -> setWindowTitle("TIC TAC TOE");

    whosTurnFirst(FirstPlayer, SecondPlayer);

    ui -> groupBox -> setTitle(FirstPlayer);

    ui -> groupBox_2 -> setTitle(SecondPlayer);

    this -> FirstPlayer = FirstPlayer;

    this -> SecondPlayer = SecondPlayer;

    QFile file("players.txt");
    QTextStream out( & file);
    QTextStream in ( & file);
    out.setCodec("UTF-8"); in .setCodec("UTF-8");
    if (QFileInfo::exists("players.txt")) { ///////////////Load OUR Player's Name At The First Run From players.txt
        Database * player = new Database;
        file.open(QFile::ReadWrite | QFile::Text);
        while (! in .atEnd()) {
            player = new Database;

            player -> Name = in .readLine();
            player -> Win = in .readLine().toInt();
            player -> Draw = in .readLine().toInt();
            player -> Lose = in .readLine().toInt();

            players.push_back( * player);

        }
    }

}

GamePage::~GamePage() {
    delete ui;
}

void GamePage::on_XButton_clicked() { //The Function Of Pressing X Button
    if (ui -> Notification -> text() == "It's " + FirstPlayer + "'s Turn") {
        int choice;
        QFont font1("Arial", 30);
        choice = ui -> spinBox_x -> value();
        if (choice == 1 && ui -> Cell1 -> text() == '1') {
            ui -> Cell1 -> setText("X");
            ui -> Cell1 -> setStyleSheet("color:blue");
            ui -> Cell1 -> setFont(font1);
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");

        } else if (choice == 2 && ui -> Cell2 -> text() == '2') {
            ui -> Cell2 -> setText("X");
            ui -> Cell2 -> setStyleSheet("color:blue");
            ui -> Cell2 -> setFont(font1);
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");

        } else if (choice == 3 && ui -> Cell3 -> text() == '3') {
            ui -> Cell3 -> setText("X");
            ui -> Cell3 -> setStyleSheet("color:blue");
            ui -> Cell3 -> setFont(font1);
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");

        } else if (choice == 4 && ui -> Cell4 -> text() == '4') {
            ui -> Cell4 -> setStyleSheet("color:blue");
            ui -> Cell4 -> setFont(font1);
            ui -> Cell4 -> setText("X");
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");

        } else if (choice == 5 && ui -> Cell5 -> text() == '5') {
            ui -> Cell5 -> setText("X");
            ui -> Cell5 -> setStyleSheet("color:blue");
            ui -> Cell5 -> setFont(font1);
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");

        } else if (choice == 6 && ui -> Cell6 -> text() == '6') {
            ui -> Cell6 -> setText("X");
            ui -> Cell6 -> setStyleSheet("color:blue");
            ui -> Cell6 -> setFont(font1);
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");

        } else if (choice == 7 && ui -> Cell7 -> text() == '7') {
            ui -> Cell7 -> setText("X");
            ui -> Cell7 -> setStyleSheet("color:blue");
            ui -> Cell7 -> setFont(font1);
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");

        } else if (choice == 8 && ui -> Cell8 -> text() == '8') {
            ui -> Cell8 -> setText("X");
            ui -> Cell8 -> setStyleSheet("color:blue");
            ui -> Cell8 -> setFont(font1);
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");


        } else if (choice == 9 && ui -> Cell9 -> text() == '9') {
            ui -> Cell9 -> setText("X");
            ui -> Cell9 -> setStyleSheet("color:blue");
            ui -> Cell9 -> setFont(font1);
            ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");

        } else {
            QMessageBox::information(this, "", "Please Select An Empty Cell");
        }

        if (CheckwinX()) {
            ui -> Notification -> setText("Winner : " + FirstPlayer);
            for (auto & x: players) {
                if (x.Name == FirstPlayer) x.Win++;
                if (x.Name == SecondPlayer) x.Lose++;
            }
            UpdateFile();
            QMessageBox::information(this, " ", "HOOORAY!\n" + FirstPlayer + " Is The Winner!!!");
        }
        else if (CheckDraw()) {
            ui -> Notification -> setText("DRAW");
            for (auto & x: players) {
                if (x.Name == SecondPlayer) x.Draw++;
                if (x.Name == FirstPlayer) x.Draw++;
            }
            UpdateFile();
            QMessageBox::information(this, " ", "OH!\nThis Game Doesn't Have Any Winner!!!");
        }

    } else {
        if(ui->Notification->text()=="DRAW" || ui->Notification->text()=="Winner : " + FirstPlayer || ui->Notification->text()=="Winner : " + SecondPlayer){
            QMessageBox::information(this, " ","Please Reset The Game");
        }
        else QMessageBox::critical(this, " ", FirstPlayer + ", It's Not Your Turn");
    }

}

void GamePage::on_OButton_clicked() { //The Function Of Pressing O Button
    if (ui -> Notification -> text() == "It's " + SecondPlayer + "'s Turn") {
        int choice;
        QFont font1("Arial", 30);
        choice = ui -> spinBox_o -> value();
        if (choice == 1 && ui -> Cell1 -> text() == '1') {
            ui -> Cell1 -> setText("O");
            ui -> Cell1 -> setStyleSheet("color:red");
            ui -> Cell1 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");

        } else if (choice == 2 && ui -> Cell2 -> text() == '2') {
            ui -> Cell2 -> setText("O");
            ui -> Cell2 -> setStyleSheet("color:red");
            ui -> Cell2 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");

        } else if (choice == 3 && ui -> Cell3 -> text() == '3') {
            ui -> Cell3 -> setText("O");
            ui -> Cell3 -> setStyleSheet("color:red");
            ui -> Cell3 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");

        } else if (choice == 4 && ui -> Cell4 -> text() == '4') {
            ui -> Cell4 -> setText("O");
            ui -> Cell4 -> setStyleSheet("color:red");
            ui -> Cell4 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");

        } else if (choice == 5 && ui -> Cell5 -> text() == '5') {
            ui -> Cell5 -> setText("O");
            ui -> Cell5 -> setStyleSheet("color:red");
            ui -> Cell5 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");

        } else if (choice == 6 && ui -> Cell6 -> text() == '6') {
            ui -> Cell6 -> setText("O");
            ui -> Cell6 -> setStyleSheet("color:red");
            ui -> Cell6 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");

        } else if (choice == 7 && ui -> Cell7 -> text() == '7') {
            ui -> Cell7 -> setText("O");
            ui -> Cell7 -> setStyleSheet("color:red");
            ui -> Cell7 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");

        } else if (choice == 8 && ui -> Cell8 -> text() == '8') {
            ui -> Cell8 -> setText("O");
            ui -> Cell8 -> setStyleSheet("color:red");
            ui -> Cell8 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");

        } else if (choice == 9 && ui -> Cell9 -> text() == '9') {

            ui -> Cell9 -> setText("O");
            ui -> Cell9 -> setStyleSheet("color:red");
            ui -> Cell9 -> setFont(font1);
            ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");
        } else {
            QMessageBox::information(this, "", "Please Select An Empty Cell");
        }

        if (CheckwinO()) {
            ui -> Notification -> setText("Winner : " + SecondPlayer);
            for (auto & x: players) {
                if (x.Name == SecondPlayer) x.Win++;
                if (x.Name == FirstPlayer) x.Lose++;
            }
            UpdateFile();
            QMessageBox::information(this, " ", "HOOORAY!\n" + SecondPlayer + " Is The Winner!!!");

        }
        else if (CheckDraw()) {
            ui -> Notification -> setText("DRAW");
            for (auto & x: players) {
                if (x.Name == SecondPlayer) x.Draw++;
                if (x.Name == FirstPlayer) x.Draw++;
            }
            UpdateFile();
            QMessageBox::information(this, " ", "OH!\nThis Game Doesn't Have Any Winner!!!");
        }

    } else {
        if(ui->Notification->text()=="DRAW" || ui->Notification->text()=="Winner : " + SecondPlayer || ui->Notification->text()=="Winner : " + FirstPlayer){
            QMessageBox::information(this, " ","Please Reset The Game");
        }
        else QMessageBox::critical(this, " ", FirstPlayer + ", It's Not Your Turn");
    }

}

void GamePage::whosTurnFirst(QString FirstPlayer, QString SecondPlayer) {/////////////Choose The First Player When The Game Starts
    int Turn;
    srand(time(0));
    Turn = rand() % 2 + 1;
    QString Player1, Player2;
    if (Turn == 1) {
        ui -> Notification -> setText("It's " + FirstPlayer + "'s Turn");
    } else {
        ui -> Notification -> setText("It's " + SecondPlayer + "'s Turn");
    }

}

bool GamePage::CheckwinX() {
    QString Cell1 = ui -> Cell1 -> text(), Cell2 = ui -> Cell2 -> text(), Cell3 = ui -> Cell3 -> text(), Cell4 = ui -> Cell4 -> text(),
            Cell5 = ui -> Cell5 -> text(), Cell6 = ui -> Cell6 -> text(), Cell7 = ui -> Cell7 -> text(),
            Cell8 = ui -> Cell8 -> text(), Cell9 = ui -> Cell9 -> text();

    if (Cell1 == Cell2 && Cell2 == Cell3 && Cell3 == "X") return true;

    else if (Cell4 == Cell5 && Cell5 == Cell6 && Cell6 == "X") return true;

    else if (Cell7 == Cell8 && Cell8 == Cell9 && Cell9 == "X") return true;

    else if (Cell1 == Cell4 && Cell4 == Cell7 && Cell7 == "X") return true;

    else if (Cell2 == Cell5 && Cell5 == Cell8 && Cell8 == "X") return true;

    else if (Cell3 == Cell6 && Cell6 == Cell9 && Cell9 == "X") return true;

    else if (Cell1 == Cell5 && Cell5 == Cell9 && Cell9 == "X") return true;

    else if (Cell3 == Cell5 && Cell5 == Cell7 && Cell7 == "X") return true;

    else if (Cell1 != '1' && Cell2 != '2' && Cell3 != '3' &&
             Cell4 != '4' && Cell5 != '5' && Cell6 != '6' &&
             Cell7 != '7' && Cell8 != '8' && Cell9 != '9') {

        return false;

    }

}

bool GamePage::CheckwinO() {
    QString Cell1 = ui -> Cell1 -> text(), Cell2 = ui -> Cell2 -> text(), Cell3 = ui -> Cell3 -> text(), Cell4 = ui -> Cell4 -> text(),
            Cell5 = ui -> Cell5 -> text(), Cell6 = ui -> Cell6 -> text(), Cell7 = ui -> Cell7 -> text(),
            Cell8 = ui -> Cell8 -> text(), Cell9 = ui -> Cell9 -> text();

    if (Cell1 == Cell2 && Cell2 == Cell3 && Cell3 == "O") return true;

    else if (Cell4 == Cell5 && Cell5 == Cell6 && Cell6 == "O") return true;

    else if (Cell7 == Cell8 && Cell8 == Cell9 && Cell9 == "O") return true;

    else if (Cell1 == Cell4 && Cell4 == Cell7 && Cell7 == "O") return true;

    else if (Cell2 == Cell5 && Cell5 == Cell8 && Cell8 == "O") return true;

    else if (Cell3 == Cell6 && Cell6 == Cell9 && Cell9 == "O") return true;

    else if (Cell1 == Cell5 && Cell5 == Cell9 && Cell9 == "O") return true;

    else if (Cell3 == Cell5 && Cell5 == Cell7 && Cell7 == "O") return true;

    else if (Cell1 != '1' && Cell2 != '2' && Cell3 != '3' &&
             Cell4 != '4' && Cell5 != '5' && Cell6 != '6' &&
             Cell7 != '7' && Cell8 != '8' && Cell9 != '9') {

        return false;

    }
}

bool GamePage::CheckDraw() {
    QString Cell1 = ui -> Cell1 -> text(), Cell2 = ui -> Cell2 -> text(), Cell3 = ui -> Cell3 -> text(), Cell4 = ui -> Cell4 -> text(),
            Cell5 = ui -> Cell5 -> text(), Cell6 = ui -> Cell6 -> text(), Cell7 = ui -> Cell7 -> text(),
            Cell8 = ui -> Cell8 -> text(), Cell9 = ui -> Cell8 -> text();

    if (Cell1 != '1' && Cell2 != '2' && Cell3 != '3' &&
        Cell4 != '4' && Cell5 != '5' && Cell6 != '6' &&
        Cell7 != '7' && Cell8 != '8' && Cell9 != '9') {

        if (!CheckwinX() || !CheckwinO()) return true;

    } else {
        return false;
    }
}

void GamePage::on_ResetButton_clicked() {////////////////////////////////Clear The Board To Start A New Game Between Current Players
    QFont font("MS Shell Dlg 2", 10);
    ui -> Cell1 -> setText("1");
    ui -> Cell1 -> setFont(font);
    ui -> Cell1 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");
    ui -> Cell2 -> setText("2");
    ui -> Cell2 -> setFont(font);
    ui -> Cell2 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");
    ui -> Cell3 -> setText("3");
    ui -> Cell3 -> setFont(font);
    ui -> Cell3 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");
    ui -> Cell4 -> setText("4");
    ui -> Cell4 -> setFont(font);
    ui -> Cell4 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");
    ui -> Cell5 -> setText("5");
    ui -> Cell5 -> setFont(font);
    ui -> Cell5 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");
    ui -> Cell6 -> setText("6");
    ui -> Cell6 -> setFont(font);
    ui -> Cell6 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");
    ui -> Cell7 -> setText("7");
    ui -> Cell7 -> setFont(font);
    ui -> Cell7 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");
    ui -> Cell8 -> setText("8");
    ui -> Cell8 -> setFont(font);
    ui -> Cell8 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");
    ui -> Cell9 -> setText("9");
    ui -> Cell9 -> setFont(font);
    ui -> Cell9 -> setStyleSheet("background-color: transparent;"
                             "color : #e0dddd;");

    whosTurnFirst(FirstPlayer, SecondPlayer);
    QMessageBox::information(this, " ", "The Board Was Successfully  Reseted");
}

void GamePage::UpdateFile() {//////////////////////////////////////////Update The Fila(the game is finished)
    QFile file("players.txt");
    QTextStream out( & file);
    out.setCodec("UTF-8");
    file.open(QFile::WriteOnly | QFile::Text);
    for (auto x: players) {
        out << x.Name << "\n";
        out << x.Win  << "\n";
        out << x.Draw << "\n";

        if(x.Name==players.back().Name) out << x.Lose ;
        else out << x.Lose << "\n";
    }
    file.close();
}

void GamePage::on_BackButton_clicked() {/////////////////////////////////Back To The First Page
    this -> close();
    Firstpage -> show();
}
