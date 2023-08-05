#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

DWORD WINAPI task(LPVOID lpParameter);

typedef struct names {
	LPCSTR first_name;
	LPCSTR last_name;

}NAMES;

DWORD WINAPI task(LPVOID lpParameter)
{
	NAMES* my_name = (NAMES*)lpParameter;
	//print parameter
	LPCSTR first_name = my_name->first_name;
	LPCSTR last_name = my_name->last_name;
	LPSTR full_name = (LPSTR) malloc(20);

	sprintf_s(full_name, 20, "%s %s", first_name, last_name);
	//strcpy_s(full_name, 20, first_name);
	//strcat_s(full_name, 20, " ");
	//strcat_s(full_name, 20, last_name);
	printf("full name = %s\n", full_name);
	
}

int main() {
	int thread_num = 3;
	HANDLE threads[3];

	NAMES my_name;
	my_name.first_name = "Jay";
	my_name.last_name = "Smeth";
	//task(&my_name);
	for (int i = 0; i < thread_num; i++) {
		threads[i] = CreateThread(NULL, 0, task, &my_name, 0, NULL);
		if (threads[i] == NULL) {
			printf("CreateThread number %d failed with error code %d\n", i+1, GetLastError());
			return 1;
		}
	}
	WaitForMultipleObjects(3, threads, TRUE, INFINITE);
	printf("main is done\n");
}