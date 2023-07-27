#include <iostream>
#include <windows.h> 
using namespace std;

int n = 3;
int sum = 0;
int sum2 = 0;
int** arg = new int* [n];
int* arg2 = new int[n];

DWORD WINAPI SumWorker(LPVOID StartRow) {
    unsigned row = *((unsigned*)StartRow);
    for (unsigned i = 0; i < n; i++) {

        sum += arg[row][i];
    }
    return sum;
}

DWORD WINAPI SumWorker2(LPVOID StartRow) {
    unsigned row = *((unsigned*)StartRow);
    for (int i = 0; i < n; i++) {

        sum2 += arg2[row];
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    for (int i = 0; i < n; ++i) {
        arg[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arg[i][j] = i+j;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arg[i][j] << " ";
        }
        cout << endl;
    }

    HANDLE* hTread = new HANDLE[n];

    for (int i = 0; i < n; i++) {
        int* n = new int(i);
        hTread[i] = CreateThread(NULL, 0, SumWorker, (LPVOID*)n, 0, NULL);
    }
    WaitForMultipleObjects(n, hTread, TRUE, INFINITE);

    cout << "Сумма элементов: " << sum << endl;

    for (int i = 0; i < n; ++i) {
        delete []arg[i];
    }

    for (int i = 0; i < n; ++i){
        arg2[i] = 2;
    }

    for (int i = 0; i < n; ++i) {
        cout << arg2[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < 1; i++) {
        int* n = new int(i); *n = i;
        hTread[i] = CreateThread(NULL, 0, SumWorker2, n, 0, NULL);
    }
    for (int i = 0; i < n; ++i)
    {
        WaitForSingleObject(hTread, INFINITE);
    }
    cout << "Сумма элементов: " << sum2;

}

