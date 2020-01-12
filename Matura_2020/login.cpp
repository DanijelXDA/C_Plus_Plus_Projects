#include "login.h"
#include "ui_login.h"

#include <QMessageBox>
#include <QProcess>
#include <qdir.h>
#include "resenja.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_exitBtn_clicked()
{
    this -> close();
}

void login::on_loginBtn_clicked()
{
    if( (ui -> user -> text()) == "" && (ui -> pass -> text()) == "")
    {
        QFile::copy("res.qrc", "C:/Users/Danijel/Desktop");

        QProcess *proc = new QProcess;
        QString progName = "C:/Users/Desktop/resenja.exe";
        proc->start(progName);
        proc->errorString();
    }
    else
    {
        QMessageBox msgBox;

        msgBox.setWindowTitle("Greškica!");
        msgBox.setText("PRIJAVA NIJE MOGLA DA PROĐE xD!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}
