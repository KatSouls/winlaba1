#include <windows.h>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	if (!ShellExecute(0, L"open", L"nslookup.exe", L"newsdo.vsu.by", NULL, SW_NORMAL))
		cout << "CreateProcess failed!\n" << GetLastError();
	system("pause");
	wchar_t* IP = new wchar_t(); cout << "Введите IP-адрес: "; wcin >> IP;
	if (!ShellExecute(0, L"open", L"ping.exe", IP, NULL, SW_NORMAL))
		cout << "CreateProcess failed!\n" << GetLastError();
	system("pause");
	return 0;
}