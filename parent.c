#include <stdio.h>
<<<<<<< HEAD

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

=======
#include <unistd.h>

int main(void)
{
	int a = 10;
	int b = 10;
	int result = a * b;

	pid_t ppid = getppid();

	printf("Multplication result is: %u\n", result);
	printf("ppid is: %u\n", ppid);

	return 0;
}
>>>>>>> 549b360eb7f81151ff25fd97d7f974919d41b9bd
