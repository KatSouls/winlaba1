#include <iostream> 
#include <stdio.h> 
#include <Windows.h> 

using namespace std;
DWORD WINAPI WorkerThread(LPVOID param) //функция – точка входа в поток
{
    while (true) {
        int i = *(int*)param;
        cout << "айди: " << i << endl;
        Sleep(1000);
    }
    return 0;
}


int main()
{
    setlocale(LC_CTYPE, "RUS");
    int N = 0;
    cout << "Введите количетво потоков:"; cin >> N;

    HANDLE* hTreads = new HANDLE[N]; //динамический массив (hTreads - указатель на массив)
    for (int i = 0; i < N; i++) {
        int* n = new int(i);
        hTreads[i] = CreateThread(NULL, 0, WorkerThread, n, 0, NULL); //создание потоков 
    }
    system("pause");

    for (int i = 0; i < N; i++) {
        TerminateThread(hTreads[i], 0); //убираются потоки
    }

    WaitForMultipleObjects(N, hTreads, TRUE, INFINITE);// функция, которая ждёт пока они отработают
    system("pause");

    return 0;
}