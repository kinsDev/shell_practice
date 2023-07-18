#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	printf("Before fork\n");

	pid = fork();

	if (pid == -1)
	{
		perror("Fork was unsuccessful\n");
		return 1;
	}
	else if(pid == 0)
	{
		printf("Child process\n");
	}
	else
	{
		wait(NULL);
		sleep(30);
		printf("Iam the parent process\n");
	}

	return 0;
}
