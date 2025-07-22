#include "form2.h"
#include "ui_form2.h"
#include "form5.h"


form2::form2(QVector<int> numbers, QWidget *parent) //numbers tu list of number from previous mainwindow.cpp
    : QMainWindow(parent),
    ui(new Ui::form2)
{
    ui->setupUi(this);

    // keep original copy
    originalNumbers = numbers; //keep unsorted number sbb nk guna kt visualization nnti form5.cpp

    // perform bubble sort to show final result call function
    bubbleSort(numbers);
    sortedNumbers = numbers; //store number yg dh sorted

    // show first 5 sorted numbers in labels
    if (numbers.size() >= 5) {
        ui->lbl1Bubble->setText(QString::number(numbers[0]));
        ui->lbl2Bubble->setText(QString::number(numbers[1]));
        ui->lbl3Bubble->setText(QString::number(numbers[2]));
        ui->lbl4Bubble->setText(QString::number(numbers[3]));
        ui->lbl5Bubble->setText(QString::number(numbers[4]));
    }
}

form2::~form2()
{
    delete ui;
}

// simple bubble sort for final result
void form2::bubbleSort(QVector<int> &arr)
{
    int n = arr.size(); //size array(nombor yg kita boleh insert kan 5 je, so automatically arr.size() = 5
    for (int i = 0; i < n - 1; ++i) { //i : number of passes sbb dlm bubbleSort kita ade pass
        for (int j = 0; j < n - i - 1; ++j) { //compare no yg bersebelahan mcm yg kita belajar la tpi bersebelahan dlm ni kiranya dri segi vertical
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// collect steps per pass (array state after each pass)
QVector<QVector<int>> form2::bubbleSortWithSteps(QVector<int> arr)
{
    QVector<QVector<int>> steps;
    int n = arr.size();

    for (int pass = 0; pass < n - 1; ++pass) //pass akan count how many pass dh siap
    {
        // Salin array untuk manipulasi
        QVector<int> tempArr = arr; //temp ni just a copy currently while doing bubble sort

        // Grid untuk pass ini
        QVector<int> grid; //grid ni akan store how many pass have been done

        for (int j = 0; j < n - 1 - pass; ++j)
        {
            if (tempArr[j] > tempArr[j + 1]) {  //yg ni buat balik bubbleSort tadi
                int t = tempArr[j];
                tempArr[j] = tempArr[j + 1];
                tempArr[j + 1] = t;
            }

            // satu kolum siap → tambah ke grid
            for (int r = 0; r < n; ++r)
            {
                grid.push_back(tempArr[r]); //dah handle that adjacent pair, copy and paste masuk dalam satu vector kosong sbb nnti kita akan guna dye utk visualization nk msukkan dalam setiap pass tu
            }
        }

        // Simpan grid untuk pass ni
        steps.push_back(grid);  //simpan value grid tu dh keberapa after dh hbes loop grid ni kiranya number of pass

        // update arr untuk pass seterusnya
        arr = tempArr; //copy balik susunan tempArr yg skrg dlm arr, sbb arr ni akan digunakan later untuk susunan pass yg keseterusnya

        // ✅ Tambah check: kalau array sekarang dah sorted, berhenti
        bool alreadySorted = true; //sbb kita tatau the exact pass utk setiap susunan nombor tu berapa, currently max untuk 5 number is 4 pass je
        for (int k = 0; k < n - 1; ++k)
        {
            if (arr[k] > arr[k + 1]) {
                alreadySorted = false; //found one pair yg belum unsorted lagi utk pass tu then break so dye tk stop la create new pass
                break;
            }
        }
        if (alreadySorted) break;
    }


    return steps;
}




void form2::on_btnShowSteps_clicked() //bukan form5.ui
{
    QVector<QVector<int>> steps = bubbleSortWithSteps(originalNumbers);
    form5 *visual = new form5(steps, this);
    this->close();
    visual->show();
}
