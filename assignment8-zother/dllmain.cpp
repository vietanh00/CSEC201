// dllmain.cpp : Defines the entry point for the DLL application.
#include "framework.h"
#include <stdio.h>
extern "C" __declspec(dllexport) int function1(int x, int y) {
    return x + y;
}
extern "C" __declspec(dllexport) void function2(char* cmd) {
    //STARTUPINFO si;
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


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

