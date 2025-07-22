#ifndef FORM3_H
#define FORM3_H

#include <QMainWindow>
#include <QVector>
#include "form4.h"

namespace Ui {
class form3;
}

class form3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form3(QVector<int> numbers, QWidget *parent = nullptr);
    ~form3();

private slots:
    void on_btnShowSteps_clicked();

private:
    Ui::form3 *ui;
    QVector<int> originalNumbers;
    QVector<int> sortedNumbers; //store sorted numbers to pass to form4
    void mergeSort(QVector<int> &arr, int left, int right);
    void merge(QVector<int> &arr, int left, int mid, int right);
};

#endif // FORM3_H
