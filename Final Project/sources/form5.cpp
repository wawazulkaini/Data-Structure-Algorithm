#include "form5.h"
#include "ui_form5.h"

form5::form5(const QVector<QVector<int>> &steps, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::form5),
    allSteps(steps) //accept senarai semua langkah from bubbleSortWithSteps from form2.cpp
{
    ui->setupUi(this);

    currentPass = 0;  //start dri kosong tunjuk pass pertama
    showCurrentPass();

    // set initial button states
    ui->btnPrev->setEnabled(false);
    ui->btnNext->setEnabled(allSteps.size() > 1);

}

form5::~form5()
{
    delete ui;
}

void form5::showCurrentPass()
{
    // bersihkan semua label dulu
    QVector<QLabel*> labels = {
        ui->lbl1Bubble, ui->lbl2Bubble, ui->lbl3Bubble, ui->lbl4Bubble, ui->lbl5Bubble,
        ui->lbl6Bubble, ui->lbl7Bubble, ui->lbl8Bubble, ui->lbl9Bubble, ui->lbl10Bubble,
        ui->lbl11Bubble, ui->lbl12Bubble, ui->lbl13Bubble, ui->lbl14Bubble, ui->lbl15Bubble,
        ui->lbl16Bubble, ui->lbl17Bubble, ui->lbl18Bubble, ui->lbl19Bubble, ui->lbl20Bubble
    };
    for (QLabel *lbl : labels)
    {
        lbl->clear();
        lbl-> setStyleSheet("background-color:white; border:1px solid black; color:black; padding:3px;");
    }

    const QVector<int> &grid = allSteps[currentPass]; //ambil satu langkah pass from allSteps based on currentPass yg kberapa , grid tu ialah vector yg simpan no no pada langkah currentPass tu
    int totalCells = grid.size(); //kira jumlah smua nombor dalam grid ; eg: 5 x 4 col, grid.size() = 20
    int rows = 5; // awak fixed 5 sbb setiap pass ade 5 nombor dalam satu column
    int cols = totalCells / rows; // auto detect kolum ikut pass; eg: 20/5 = 4 column


    for (int c = 0; c < cols; ++c) //loop ikut column,c and row,r baca nombor dri grid pastu masukkan dlm lbl tadi
    {
        for (int r = 0; r < rows; ++r) //loop ikut baris
        {
            int indexInGrid = c * rows + r; // ambil no ikut susunan column //indexInGrid : position number in grid
            int labelIndex = c * rows + r;  // mapping ke index label yg sama //labelIndex : label mane yg nk diinsert no tu
            if (labelIndex < labels.size() && indexInGrid < grid.size())
            {
                labels[labelIndex]->setText(QString::number(grid[indexInGrid]));
            }
        }
    }

    //yg ni part nk msukkan color biru(border) ngn merah(text), nk tunjuk yg adjacent pair tu tgh compare with eo

    if (cols >= 1) {
        QVector<QPair<int,int>> pairs = { //highlight adjacent pair yg tgh dibandingkan
            {0, 1},   // lbl1 & lbl2 (col0)
            {6, 7},   // lbl7 & lbl8 (col1)
            {12, 13}, // lbl13 & lbl14 (col2)
            {18, 19}  // lbl19 & lbl20 (col3)
        };

        for (const auto &p : pairs) {
            int idxA = p.first; //index pertama between adjacent pairs
            int idxB = p.second; //index kedua between adjacent pairs

            if (idxA < labels.size() && idxB < labels.size() &&
                idxA < grid.size()   && idxB < grid.size()) { //yg ni utk make sure index tu tk lebih jumlah label and jumlah no grid.size()

                // default style (border biru, teks hitam)
                labels[idxA]->setStyleSheet("background-color:white; border:2px solid blue; color:red;");
                labels[idxB]->setStyleSheet("background-color:white; border:2px solid blue; color:red;");


            }
        }

    }

    // kosongkan label tertentu ikut current pass
    if (currentPass == 1) {
        for (int i = 15; i <= 19 && i < labels.size(); ++i) {
            labels[i]->clear();
            labels[i]->setStyleSheet("border-color: rgb(251, 242, 255);"); //yg ni ikutkan nk bagi dye sama color dengan background app kita lah
        }
    }
    else if (currentPass == 2) {
        for (int i = 10; i <= 19 && i < labels.size(); ++i) {
            labels[i]->clear();
            labels[i]->setStyleSheet("border-color: rgb(251, 242, 255);");
        }
    }
    else if (currentPass == 3) {

        for (int i = 5; i <= 19 && i < labels.size(); ++i) {
            labels[i]->clear();
            labels[i]->setStyleSheet("border-color: rgb(251, 242, 255);");
        }
    }




}



void form5::on_btnPrev_clicked()
{

    if (currentPass > 0) {
        currentPass--;
        showCurrentPass();
    }

    ui->btnPrev->setEnabled(currentPass > 0); //kalau ade pass before that btnPrev enabled
    ui->btnNext->setEnabled(currentPass < allSteps.size() - 1);
}


void form5::on_btnNext_clicked()
{
    if (currentPass < allSteps.size() - 1) {
        currentPass++;
        showCurrentPass();
    }

    ui->btnPrev->setEnabled(currentPass > 0); //kalau ade pass after that btnPrev enabled
    ui->btnNext->setEnabled(currentPass < allSteps.size() - 1);
}



