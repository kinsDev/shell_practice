#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = fork();

	if(pid == -1)
	{
		perror("Error:\n");
		return 1;
	}

	if(pid == 0)
	{
		sleep(40);
		printf("I am the child\n");
		pid = getpid();
		printf("Child pid is: %u\n", pid);
	}

	else
	{
		ppid = getpid();
		printf("Parent pid is: %u\n", ppid);
	}

	return 0;
}
