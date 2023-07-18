#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	char *argv[] = {"/bin/ls", "-l", NULL}; //argument to run the ls -l command
        
        pid = fork(); //creating child process same copy as parent process and assigning it to fork
        //first we have to run the child process
	if(pid == -1)
	{
		return -1;
	}
	if (pid == 0)
	{
		//execve() is called to replace the child process
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error\n");
		}
	}
	//parent process should wait for child to finifh executing
	else
	{
		wait(NULL);
		printf("Successful operation\n");
	}
}
