#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//size of string will be allocated to 10 by malloc
	//buffer pointer is used to store the character
	size_t n = 10;
	char *buf = malloc(sizeof(char) * n);

	//get line takes in the buffer and size  address
	//stdin is for the keyboard input - *stream 
	printf("Enter name: ");
	getline(&buf, &n, stdin);

	printf("Name is %sBuffer size is %ld\n", buf, n);

	//once we are done we need to make sure that we free the buffer
	//to make sure that there are no memory leaks
	free(buf);

	return 0;
}
