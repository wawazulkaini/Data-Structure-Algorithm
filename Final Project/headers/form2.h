#ifndef FORM2_H
#define FORM2_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class form2;
}

class form2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form2(QVector<int> numbers, QWidget *parent = nullptr);
    ~form2();

private slots:
    void on_btnShowSteps_clicked();

private:
    Ui::form2 *ui;
    QVector<int> originalNumbers;
    QVector<int> sortedNumbers;

    void bubbleSort(QVector<int> &arr);
    QVector<QVector<int>> bubbleSortWithSteps(QVector<int> arr);
};

#endif // FORM2_H
