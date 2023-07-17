#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 * 
 * Return: Always 0
*/

int main(void)
{
	int a = 5, b = 7;
	int multi = a * b;

	pid_t my_pid;
	my_pid = getpid();

	printf("%d\n", multi);
	printf("%u\n", my_pid);

        return 0;
}
