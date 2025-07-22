#ifndef FORM4_H
#define FORM4_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class form4;
}

class form4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit form4(QVector<int> numbers, QWidget *parent = nullptr);
    ~form4();

private:
    Ui::form4 *ui;

    // helper functions to update each row
    void showOriginal(const QVector<int> &numbers);
    void showRow1(const QVector<int> &numbers);   // ✅ declare here
    void showRow2(const QVector<int> &numbers);   // ✅ declare here
    void showRow3left(const QVector<int> &numbers);  // ✅ add
    void showRow3right(const QVector<int> &numbers);
    void showRow4(const QVector<int> &numbers);  // ✅ add
    void showRow5(const QVector<int> &numbers);
    void showFinal(const QVector<int> &numbers);  // ✅ already existed before
};

#endif // FORM4_H
