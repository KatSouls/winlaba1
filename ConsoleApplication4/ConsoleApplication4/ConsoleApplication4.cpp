#include <windows.h> 
#include <iostream> 
#include <cmath> 
using namespace std;
double a, b; int k, n;
DWORD WINAPI CalculateIntegral(LPVOID StartRow) {
    int row = *((int*)StartRow);
    cout  << (pow((row - 4), 3) - pow((row - k - 4), 3)) / 3 << endl;
    return 0;
}

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите отрезок [a;b]: ";
    cin >> a >> b;
    cout << "Введите k точек разбиения: ";
    cin >> k;
    cout << "Введите n - количество потоков: ";
    cin >> n;

    HANDLE* hTread = new HANDLE[n];
    double x2 = a + k;
    if (x2 > b) x2 = b;
    int i = 0;
    while (x2 <= b && i < n) {
        int* n = new int(x2);
        hTread[i] = CreateThread(NULL, 0, CalculateIntegral, (LPVOID*)n, 0, NULL);
        i++; x2 += k;
    }
    WaitForMultipleObjects(n, hTread, TRUE, INFINITE);
    return 0;
}