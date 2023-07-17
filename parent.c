#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(void)
{
    int a = 5;
    int b = 7;
    int mult = a * b;

    pid_t ppid;
    
#ifdef _WIN32
    DWORD pid = GetCurrentProcessId();
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    ppid = GetProcessId(hProcess);
    CloseHandle(hProcess);
#else
    ppid = getppid();
#endif

    printf("The result is: %d\n", mult);
    printf("ppid is: %u\n", ppid);
    return 0;
}

