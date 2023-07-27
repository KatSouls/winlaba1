#include <windows.h>
#include <iostream>
using namespace std;
int main() {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(L"C:\\Maple 2016\\bin.X86_64_WINDOWS\\maplew.exe", NULL, NULL, NULL, FALSE,
		0, NULL, NULL, &si, &pi)) {
		cout << "CreateProcess failed!\n" << GetLastError();
	}
	system("pause");
	return 0;
}
