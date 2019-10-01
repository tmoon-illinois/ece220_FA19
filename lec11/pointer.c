#include <stdio.h>

int main()
{
    int x = 10;
    int *p;// int* p;
    int **pp;

    p = &x;
    pp = &p;
    

    printf("value of x\n");
    printf("%d\n", x);
    printf("%d\n", *p);
    printf("%d\n", **pp);

    printf("value of p\n");
    printf("%X\n", p);
    printf("%X\n", *pp);
    printf("%X\n", &x);


    printf("value of pp\n");
    printf("%X\n", pp);
    printf("%X\n", &p);
    //printf("%X\n", &&x); //not allowed



}
