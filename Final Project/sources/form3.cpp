#include "form3.h"
#include "ui_form3.h"
#include "form4.h"
#include <QVector> //used to handle dynamic list of numbers


form3::form3(QVector<int> numbers, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::form3)
{
    ui->setupUi(this); //build ui form3


    // keep a copy of the original unsorted numbers
    originalNumbers = numbers;
    mergeSort(numbers, 0, numbers.size() - 1); //call the function merge sort

    sortedNumbers = numbers; //store the sorted result

    // Display result in txt1Merge to txt5Merge
    if (numbers.size() >= 5) {
        ui->lbl1Merge->setText(QString::number(numbers[0]));
        ui->lbl2Merge->setText(QString::number(numbers[1]));
        ui->lbl3Merge->setText(QString::number(numbers[2]));
        ui->lbl4Merge->setText(QString::number(numbers[3]));
        ui->lbl5Merge->setText(QString::number(numbers[4]));
    }
}

form4 *visualMergeWindow = nullptr;

void form3::on_btnShowSteps_clicked() //this function will open up form4.ui which is MergeSort visualization
{
    this->close();
    visualMergeWindow = new form4(originalNumbers, this);
    visualMergeWindow->show();
}

form3::~form3()
{
    delete ui;
}

// Merge Sort functions
void form3::mergeSort(QVector<int> &arr, int left, int right)
{
    if (left < right) { //check if portion has more then one element; if left=right, means there's only one element left, so just stop
        int mid = (left + right) / 2; //m=find midpoint of current left side and right side
        mergeSort(arr, left, mid); //call same function again but only for left half; keeps splitting until that section becomes single elements
        mergeSort(arr, mid + 1, right);// call same function but for right half only
        merge(arr, left, mid, right);//after both halves sorted individually, call merge(0 to combine them into sorted section; updates left and right arr into sorted order
    }
}

//arr here is list of numbers, refer numbers from mainwindow.cpp ; arr.mid(startIndex, length) - it's a built in method; like cutting a slice of bread into specific size
void form3::merge(QVector<int> &arr, int left, int mid, int right) //merge two sorted parts of arr, left:starting index, mid:midpoint, right: ending index
{
    QVector<int> leftArr = arr.mid(left, mid - left + 1); //element from left to middle
    QVector<int> rightArr = arr.mid(mid + 1, right - mid); //element from mid+1 to right

    int i = 0, j = 0, k = left; //i=current index in leftArr; j=current index in rightArr; k=current index in the original list of numbers

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) { //compare current element from leftArr and rightArr
            arr[k++] = leftArr[i++];//take smaller one and write into arr[k]
        } else {
            arr[k++] = rightArr[j++]; //same goes to here
        }
    }

    while (i < leftArr.size()) arr[k++] = leftArr[i++]; //if anything left in leftArr, copy them all to arr
    while (j < rightArr.size()) arr[k++] = rightArr[j++];// if anything left in rightArr, copy them all to arr
}
