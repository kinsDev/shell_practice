#include <stdio.h>
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
