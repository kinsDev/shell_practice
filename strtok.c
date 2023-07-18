#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *src = "Jesus loves you";
    char *str = malloc(sizeof(char) *strlen(src));
    char *delim = " "; // specifies that the delimiter is a white space
    char *token;

    strcpy(str, src);

    token = strtok(str, delim);

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    return 0;
}

