#include <stdio.h>
#include <Windows.h>

void function2(char* cmd);
typedef int (*f1_t) (int x, int y) ;
typedef void (*f2_t) (char* cmd);
int main() {
	//char cmd[150] = "net user Jane /delete";
	//function2(cmd);
	
	f1_t myfunction1;
	f2_t myfunction2;

	//load library
	HMODULE mydll = LoadLibraryA("C:\\Users\\vieta\\Desktop\\csec201prog\\assignment8-an5208\\w9\\dllproject9\\Debug\\dllproject9.dll");
	if (mydll == NULL) {
		printf("LoadLibrary failed with error %d\n", GetLastError());
		return 1;
	}
	
	//Do function 1
	myfunction1 = (f1_t) GetProcAddress(mydll, "function1");
	if (myfunction1 == NULL) {
		printf("GetProcAddress failed with error %d\n", GetLastError());
		return 1;
	}
	int returned = myfunction1(10, 20);
	printf("returned = %d\n", returned);
	
	//Do function 2
	myfunction2 = (f2_t)GetProcAddress(mydll, "function2");
	if (myfunction2 == NULL) {
		printf("GetProcAddress failed with error %d\n", GetLastError());
		return 1;
	}
	char arg[150];
	strcpy_s(arg, 150, "net user");
	//myfunction2((char*)"net user");
	myfunction2(arg);

	FreeLibrary(mydll);
}

void function2(char* cmd) {
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	
	BOOL result = CreateProcessA(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	if (result == 0) {
		printf("CreateProcess failed with error %d\n", GetLastError());
		return;
	}
	printf("process id = %d\n", pi.dwProcessId);
	printf("main thread id = %d\n", pi.dwThreadId);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}