#ifndef FORM5_H
#define FORM5_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class form5;
}

class form5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form5(const QVector<QVector<int>> &steps, QWidget *parent = nullptr);
    ~form5();

private slots:
    void on_btnPrev_clicked();
    void on_btnNext_clicked();

private:
    Ui::form5 *ui;
    QVector<QVector<int>> allSteps;
    int currentPass = 0;

    void showCurrentPass();
    bool fromNext = false;
};

#endif // FORM5_H


