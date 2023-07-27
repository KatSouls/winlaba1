#include <iostream> 
#include <stdio.h> 
#include <Windows.h> 

using namespace std;
DWORD WINAPI obrabotchik(LPVOID param) {
    int i = *(int*)param;
    while(true){ 
        cout << "адрес: " << i << endl; 
        Sleep(800);
    }
    return 0;
}

int main(){
    setlocale(0, "RUS");
    int number = 0;
    cout << "Введите количество потоков:"; 
    cin >> number;

    HANDLE* hTreads = new HANDLE[number];
    for (int i = 0; i < number; i++) {
        int* par = new int(i);
        hTreads[i] = CreateThread(
       NULL,
            0,
          obrabotchik,
            par,
         0,
             NULL); 
    }
    system("pause");
    for (int i = 0; i < number; i++) {
        TerminateThread(hTreads[i], 0);
    }
    return 0;
}
