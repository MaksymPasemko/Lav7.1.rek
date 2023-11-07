#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1);
void Change(int** a, const int row1, const int row2, const int colCount, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main() {
    srand((unsigned)time(NULL));
    int Low = -31;
    int High = 54;
    int rowCount = 9;
    int colCount = 5;
    int** D = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        D[i] = new int[colCount];
    }

    Create(D, rowCount, colCount, Low, High, 0, 0);


    Print(D, rowCount, colCount, 0, 0);
    Sort(D, rowCount, colCount, 0, 0);
    cout << endl;
    Print(D, rowCount, colCount, 0, 0);
    int S = 0;
    int k = 0;
    Calc(D, rowCount, colCount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(D, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] D[i];
    delete[] D;
    return 0;
}

void Create(int** D, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            D[i][j] = Low + rand() % (High - Low + 1);
            Create(D, rowCount, colCount, Low, High, i, j + 1);
        }
        else {
            Create(D, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** D, const int rowCount, const int colCount, int i, int j) {

    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << D[i][j];
            Print(D, rowCount, colCount, i, j + 1);
        }
        else {
            cout << endl;
            Print(D, rowCount, colCount, i + 1, 0);
        }
    }
}

void Sort(int** D, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 < rowCount - 1) {
        if (i1 < rowCount - i0 - 1) {
            if (D[i1][0] > D[i1 + 1][0] ||
                (D[i1][0] == D[i1 + 1][0] &&
                    D[i1][1] < D[i1 + 1][1]) ||
                (D[i1][0] == D[i1 + 1][0] &&
                    D[i1][1] == D[i1 + 1][1] &&
                    D[i1][3] < D[i1 + 1][3])) {
                Change(D, i1, i1 + 1, colCount, 0);
            }
            Sort(D, rowCount, colCount, i0, i1 + 1);
        }
        else {
            Sort(D, rowCount, colCount, i0 + 1, 0);
        }
    }
}

void Change(int** D, const int row1, const int row2, const int colCount, int j) {
    if (j < colCount) {
        int tmp = D[row1][j];
        D[row1][j] = D[row2][j];
        D[row2][j] = tmp;
        Change(D, row1, row2, colCount, j + 1);
    }
}

void Calc(int** D, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            if (D[i][j] > 0 && D[i][j] % 5 != 0) {
                S += D[i][j];
                k++;
                D[i][j] = 0;
            }
            Calc(D, rowCount, colCount, S, k, i, j + 1);
        }
        else {
            Calc(D, rowCount, colCount, S, k, i + 1, 0);
        }
    }
}