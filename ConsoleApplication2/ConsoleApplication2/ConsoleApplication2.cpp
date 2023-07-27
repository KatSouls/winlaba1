#include <iostream>
#include <windows.h> 
using namespace std;

int n = 5;
int** arg1 = new int* [n];
int** arg2 = new int* [n];

DWORD WINAPI RazWorker(LPVOID StartRow) {
    unsigned row = *((unsigned*)StartRow);
    for (unsigned i = 0; i < n; i++) {

        arg1[row][i] -= arg2[row][i];
    }
    return 0;
}

int main()
{
    setlocale(0, "rus");
    for (int i = 0; i < n; ++i) {
        arg1[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arg1[i][j] = i + j;
        }
    }
    cout << "первая матрица: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arg1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        arg2[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arg2[i][j] = arg1[i][j] - 1;
        }
    }
    cout << "вторая матрица: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arg2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;



    HANDLE* hTread = new HANDLE[n];

    for (int i = 0; i < n; i++) {
        int* n = new int(i);
        hTread[i] = CreateThread(NULL, 0, RazWorker, (LPVOID*)n, 0, NULL);
    }
    WaitForMultipleObjects(n, hTread, TRUE, INFINITE);

    cout << "Разность первая матрица - вторая матрица : " << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arg1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        delete[]arg1[i];
    }

    for (int i = 0; i < n; ++i) {
        delete[]arg2[i];
    }
}

