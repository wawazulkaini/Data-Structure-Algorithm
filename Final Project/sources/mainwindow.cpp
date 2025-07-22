#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form2.h"
#include "form3.h"
#include <QDebug> //to print debug messages to the console



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui; //cleans memory when MainWindow is closed
}

//declare pointer to hold form2 window
form2 *bubbleWindow = nullptr; //keep pointer to form2 n form3 so we can open it later
form3 *mergeWindow = nullptr; // null : nothing assigned yet

void MainWindow::on_btnBubble_clicked()
{
    QString input = ui->txtInsert->toPlainText(); // Reads text from txtInsert
    QStringList stringList = input.split(",", Qt::SkipEmptyParts); //splits into list eg : ["13","12","1","5","21"]
    QVector<int> numbers;

    for (const QString &s : stringList) {
        numbers.append(s.trimmed().toInt()); //trims spaces and convert into integers eg: [13,12,1,5,21]
    }

    this->close();                   // Close MainWindow
    bubbleWindow = new form2(numbers,this);  // Create form2
    bubbleWindow->show();            // Show it
    qDebug() << "User input parsed:" << numbers;

}


void MainWindow::on_btnMerge_clicked()
{
    QString input = ui->txtInsert->toPlainText(); // Reads text from txtInsert
    QStringList stringList = input.split(",", Qt::SkipEmptyParts); //splits into list eg : ["13","12","1","5","21"]
    QVector<int> numbers;

    for (const QString &s : stringList) {
        numbers.append(s.trimmed().toInt()); //trims spaces and convert into integers eg: [13,12,1,5,21]
    }

    this->close();                   // Close MainWindow
    mergeWindow = new form3(numbers, this);  // Create form3, numbers tadi pass dekat sini
    mergeWindow->show();            // Show it

    qDebug() << "User input parsed:" << numbers; //just nak check input from user ade ke tak (programmer's pov, bukan ui)
}

