#include "form4.h"
#include "ui_form4.h"
using namespace std;

form4::form4(QVector<int> numbers, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::form4)
{
    ui->setupUi(this);

    // Original
    showOriginal(numbers);

    // Split into left (3) and right (2)
    QVector<int> leftHalf, rightHalf; //refer to the first row in form4.ui
    for (int i = 0; i < 3; ++i) leftHalf.push_back(numbers[i]); //unsorted number entered from user 3 from left
    for (int i = 3; i < numbers.size(); ++i) rightHalf.push_back(numbers[i]); //unsorted number entered from user 2 from right

    // Row1: display split halves
    QVector<int> row1(5);
    row1[0] = leftHalf[0];
    row1[1] = leftHalf[1];
    row1[2] = leftHalf[2];
    row1[3] = rightHalf[0];
    row1[4] = rightHalf[1];
    showRow1(row1);

    // Row2: show left two grouped, left alone, right alone, right alone
    showRow2(row1); //copy paste je row 1 sbb dye still dlm phase bahagi into 2  (merge sort kan dye split ikut bahagian masing masing dulu)

    // Row3: show first two of LEFT
    QVector<int> row3(2); //sama je ngn before, boleh tngok susunan kotak dlm
    row3[0] = leftHalf[0];
    row3[1] = leftHalf[1];
    showRow3left(row3); // ONLY left side here

    // Row3: sort first two of RIGHT
    if (rightHalf[0] > rightHalf[1]) { //compare number kalau satisfy yg ni dye akan tukar tulisan jdi wrna merah
        // kedua-duanya merah
        ui->lbl4Row3->setStyleSheet("QLabel { background-color: rgb(0, 85, 27);color: red; border: 1px solid black;}");
        ui->lbl5Row3->setStyleSheet("QLabel { background-color: rgb(0, 85, 27);color: red; border: 1px solid black; }");
    }
    QVector<int> sortedRightTwo = { rightHalf[0], rightHalf[1] };
    std::sort(sortedRightTwo.begin(), sortedRightTwo.end()); //function ni akan sort la between those 2 number
    showRow3right(sortedRightTwo); // ONLY left side here

    // Row4: sort two of LEFT
    if (leftHalf[0] > leftHalf[1]) {
        // kedua-duanya merah
        ui->lbl1Row4->setStyleSheet("QLabel { background-color:white;color: red; border: 1px solid black;}");
        ui->lbl2Row4->setStyleSheet("QLabel { background-color:white;color: red; border: 1px solid black; }");
    }
    QVector<int> sortedLeftTwo = { leftHalf[0], leftHalf[1] };
    std::sort(sortedLeftTwo.begin(), sortedLeftTwo.end());
    showRow4(sortedLeftTwo); // ONLY left side here

    // Row5: merge left side (3 numbers)

    QVector<int> mergedLeft = { sortedLeftTwo[0], sortedLeftTwo[1], leftHalf[2] };
    std::sort(mergedLeft.begin(), mergedLeft.end()); //susun yg ade 3 kotak at the same time refer form4.ui
    showRow5(mergedLeft);

    //tkde anak panah panjang, so saya buat background color jadi kuning
    if ( sortedLeftTwo[1] > leftHalf[2]) { //leftHalf tadi ade 3, so yg paling last tu color dye wrna kuning
        ui->lbl2Row5->setStyleSheet("QLabel { background-color:white;color: red; border: 1px solid black;}");
        ui->lbl3Row5->setStyleSheet("QLabel { background-color:white;color: red; border: 1px solid black;}");
        if (sortedLeftTwo[0] > leftHalf[2]){
            ui->lbl1Row5->setStyleSheet("QLabel { background-color:rgb(251, 255, 38);color: red; border: 1px solid black;}");
        } else{
            ui->lbl2Row5->setStyleSheet("QLabel { background-color:rgb(251, 255, 38);color: red; border: 1px solid black;}");
            ui->lbl3Row5->setStyleSheet("QLabel { background-color:white;color: red; border: 1px solid black;}");
        }
    } else {
        ui->lbl3Row5->setStyleSheet("QLabel { background-color:rgb(251, 255, 38);color: black; border: 1px solid black;}");
    }

    //Final merge: merge left3 and right2
    QVector<int> finalRow = { mergedLeft[0], mergedLeft[1], mergedLeft[2],
                             sortedRightTwo[0], sortedRightTwo[1] };
    std::sort(finalRow.begin(), finalRow.end());
    showFinal(finalRow);

    //bawah ni kan sbb saya buat rightHalf tu wrna hijau so bile saya turunkan dye kt final Row tu dye kene ikut wrna tu jugak

    QLabel* labels[5] = {
        ui->lbl1Final,
        ui->lbl2Final,
        ui->lbl3Final,
        ui->lbl4Final,
        ui->lbl5Final
    };

    int matchCount = 0; // kira berapa kali dah highlight hijau


    for (int i = 0; i < finalRow.size() && i < 5; ++i) {
        bool isMatch = false;

        // check dengan setiap elemen dalam sortedRightTwo
        for (int j = 0; j < sortedRightTwo.size(); ++j) {
            if (finalRow[i] == sortedRightTwo[j]) {
                isMatch = true;
                break; // tak perlu check lagi
            }
        }

        // tukar warna ikut condition
        if (isMatch && matchCount < 2) {
            labels[i]->setStyleSheet(
                "QLabel { background-color:rgb(0, 85, 27); color: black; border: 1px solid black; }"
                );
            matchCount++;
        } else {
            labels[i]->setStyleSheet(
                "QLabel { background-color:white; color:black; border: 1px solid black; }"
                );
        }
    }
}


form4::~form4()
{
    delete ui;
}

// --------------------- HELPER FUNCTIONS ---------------------

void form4::showOriginal(const QVector<int> &n) {
    ui->lbl1Ori->setText(QString::number(n[0]));
    ui->lbl2Ori->setText(QString::number(n[1]));
    ui->lbl3Ori->setText(QString::number(n[2]));
    ui->lbl4Ori->setText(QString::number(n[3]));
    ui->lbl5Ori->setText(QString::number(n[4]));
}

void form4::showRow1(const QVector<int> &n) {
    ui->lbl1Row1->setText(QString::number(n[0]));
    ui->lbl2Row1->setText(QString::number(n[1]));
    ui->lbl3Row1->setText(QString::number(n[2]));
    ui->lbl4Row1->setText(QString::number(n[3]));
    ui->lbl5Row1->setText(QString::number(n[4]));
}

void form4::showRow2(const QVector<int> &n) {
    ui->lbl1Row2->setText(QString::number(n[0]));
    ui->lbl2Row2->setText(QString::number(n[1]));
    ui->lbl3Row2->setText(QString::number(n[2]));
    ui->lbl4Row2->setText(QString::number(n[3]));
    ui->lbl5Row2->setText(QString::number(n[4]));
}

void form4::showRow3left(const QVector<int> &n) {
    ui->lbl1Row3->setText(QString::number(n[0]));
    ui->lbl2Row3->setText(QString::number(n[1]));
}

void form4::showRow3right(const QVector<int> &n) {
    ui->lbl4Row3->setText(QString::number(n[0]));
    ui->lbl5Row3->setText(QString::number(n[1]));
}

void form4::showRow4(const QVector<int> &n) {
    ui->lbl1Row4->setText(QString::number(n[0]));
    ui->lbl2Row4->setText(QString::number(n[1]));
    // ui->lbl3Row4->setText(QString::number(n[2])); // stay commented
    // ui->lbl4Row4->setText(QString::number(n[3])); // stay commented
    // ui->lbl5Row4->setText(QString::number(n[4])); // stay commented
}

void form4::showRow5(const QVector<int> &n) {
    ui->lbl1Row5->setText(QString::number(n[0]));
    ui->lbl2Row5->setText(QString::number(n[1]));
    ui->lbl3Row5->setText(QString::number(n[2]));
    // ui->lbl4Row5->setText(QString::number(n[3])); // stay commented
    // ui->lbl5Row5->setText(QString::number(n[4])); // stay commented
}

void form4::showFinal(const QVector<int> &n) {
    ui->lbl1Final->setText(QString::number(n[0]));
    ui->lbl2Final->setText(QString::number(n[1]));
    ui->lbl3Final->setText(QString::number(n[2]));
    ui->lbl4Final->setText(QString::number(n[3]));
    ui->lbl5Final->setText(QString::number(n[4]));
}
