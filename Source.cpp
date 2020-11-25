// Lab_7_2_1.cpp
// < Ратушна Соломія Юріївна >
// Лабораторна робота № 7.2.1
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 22
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void SearchMaxMinEvenSort(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    cout << "n = "; cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    Create(a, n, Low, High);
    Print(a, n);

    cout << endl;
    SearchMaxMinEvenSort(a, n);
    Print(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SearchMaxMinEvenSort(int** a, const int n)
{
    int max = a[0][1];
    int min = a[1][0];
    int max_i = 0;
    int min_i = 1;
    int max_j = 1;
    int min_j = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1 + i; j < n; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                max_i = i; max_j = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1 + i; j < n; j++)
        {
            if (a[j][i] < min)
            {
                min = a[j][i];
                min_i = j; min_j = i;
            }
        }
    }

    int sum = max + min;
    cout << endl;
    cout << "sum = " << sum << endl;

    int tpm = max;
    a[max_i][max_j] = min;
    a[min_i][min_j] = tpm;
}