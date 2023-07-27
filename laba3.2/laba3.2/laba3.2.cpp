#include <windows.h> 
#include <iostream> 
#include <random> 

using namespace std;

int sum = 0;
int N = 0;
int** M = NULL;



//Сумма по строкам
DWORD WINAPI Worker(LPVOID startStrIndx) {
    int strIndx = *((int*)startStrIndx);
    int testSum = 0;
    for (int i = 0; i < N; i++) {
        testSum += M[strIndx][i];
    }
    sum += testSum;
    cout << "potok sum: " << testSum << endl;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Кол. эл. n^2 : ";
    cin >> N;

    //созд 2мер. масс.
    M = new int* [N];
    for (int i = 0; i < N; i++) {
        M[i] = new int[N];
    }



    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[i][j] =  rand() % 10;
            cout << M[i][j] << "|";
        }
        cout << "\n";
    }

    HANDLE* hTreads = new HANDLE[N];
    for (int i = 0; i < N; i++) {
        int* n = new int(i);
        hTreads[i] = CreateThread(NULL, 0, Worker, n, 0, NULL);
    }
    WaitForMultipleObjects(N, hTreads, TRUE, INFINITE);

    cout << "Общая сумма: " << sum;
    return 0;
}