#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int*) malloc(sizeof(int));

    *ptr = 10;

    int *temp;
    temp = (int*) realloc(ptr, 4*sizeof(int));
    if(temp == NULL)
        return -1;
    else
        ptr = temp;

    free(ptr);



}
