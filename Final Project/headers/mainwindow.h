#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//This file is like a blueprint — it tells your app what MainWindow is and connects to the UI.

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnBubble_clicked();

    void on_btnMerge_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
