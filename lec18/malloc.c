#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int*) malloc(sizeof(int));

    *ptr = 10;

    int *ptr2 = (int*) malloc(sizeof(int));

    *ptr2 = 5;

    free(ptr);//free memory of number 10
    ptr = ptr2;

    free(ptr);
    //free(ptr2);

}
