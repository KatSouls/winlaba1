#include <windows.h>
#include <iostream>
using namespace std;
int main() {
	ShellExecute(0, L"open", L"C:\\test\\TEST.txt", NULL, NULL, SW_NORMAL);
	system("pause");
	return 0;
}
