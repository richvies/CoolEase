#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char* c = "Hello therer\n";
    //char* d = malloc(sizeof(c));
    //strcpy(d, c);
    printf("%c Size: %li\n", *(c+1), strlen(c));
    //printf("%s Size: %li\n", d, sizeof(d));
}