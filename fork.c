#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("Before fork I was one\n");

	pid = fork();

	if(pid == -1)
	{
		perror("Was unsuccessful\n");
		return 1;
	}

	if(pid == 0)
	{
		printf("I am the child process\n");
	}

	else
	{
		printf("I am the parent process\n");
	}

	printf("After fork I became two\n");

	return 0;
}
