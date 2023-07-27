// Критическая секция

#include <iostream>
#include <windows.h>
using namespace std;

int m[25];

CRITICAL_SECTION criticalSection; // переменная для критической секции

DWORD WINAPI ThreadFunc(LPVOID lpParam) {
	// входим в критическую секцию
	EnterCriticalSection(&criticalSection);

	for (int i = 0; i < 25; i++)
		cout << m[i] << " ";
	cout << endl;

	// выходим из критической секции
	LeaveCriticalSection(&criticalSection);

	return 0;
}


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// инициализируем критическую секцию
	InitializeCriticalSection(&criticalSection);

	cout << "Вывод двух возрастающих последовательностей:"
		<< endl;
	for (int i = 0; i < 25; m[i++] = i);
	HANDLE Th;
	Th = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	// входим в критическую секцию
	EnterCriticalSection(&criticalSection);

	for (int i = 0; i < 25; i++)
		cout << m[i] << " ";
	cout << endl;

	// выходим из критической секции
	LeaveCriticalSection(&criticalSection);

	WaitForSingleObject(Th, INFINITE);
	CloseHandle(Th);
	// удаляем критическую секцию
	DeleteCriticalSection(&criticalSection);
	system("pause");
	return 0;
}

/*
		Критические секции обеспечивают синхронизацию подобно мьютексам
		за исключением того, что объекты, представляющие критические секции,
		доступны в пределах одного процесса. События, мьютексы и семафоры
		также можно использовать в "однопроцессном" приложении, однако
		критические секции обеспечивают более быстрый и более эффективный
		механизм взаимно-исключающей синхронизации. Подобно мьютексам объект,
		представляющий критическую секцию, может использоваться только одним
		потоком в данный момент времени, что делает их крайне полезными при
		разграничении доступа к общим ресурсам. Трудно предположить что-нибудь
		о порядке, в котором потоки будут получать доступ к ресурсу, можно
		сказать лишь, что система будет "справедлива" ко всем потокам.

		void InitializeCriticalSection(					Инициализирует объект критической секции.
			LPCRITICAL_SECTION	lpCriticalSection		Указатель на объект критической секции.
		);

		void EnterCriticalSection(						Ожидает владения указанным объектом критической секции.
														Функция возвращается, когда вызывающему потоку предоставлено
														право собственности.
			LPCRITICAL_SECTION	lpCriticalSection		Указатель на объект критической секции.
		);

		void LeaveCriticalSection(						Освобождает владение указанным объектом критической секции.
			LPCRITICAL_SECTION	lpCriticalSection		Указатель на объект критической секции.
		);

		void DeleteCriticalSection(						Освобождает все ресурсы, используемые объектом критического раздела.
			LPCRITICAL_SECTION	lpCriticalSection		Указатель на объект критической секции.
		);
*/
