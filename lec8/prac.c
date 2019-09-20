#include <stdio.h>

int main()
{
    int a = 6, b = 9;


    printf("%-15s%-15s\n", "Expression", "Value of Exp");
    printf("%-15s%-15d\n", "a | b", a | b);
    printf("%-15s%-15d\n", "a || b", a || b);
    printf("%-15s%-15d\n", "a & b", a & b);
    printf("%-15s%-15d\n", "a && b", a && b);
    printf("%-15s%-15d\n", "!(a + b)", !(a + b) );
    printf("%-15s%-15d\n", "a % b", a % b);
    printf("%-15s%-15d\n", "b / a", b / a);
    printf("%-15s%-15d\n", "a = b", a = b);
    printf("%-15s%-15d\n", "a = b = 5", a = b = 5);
    printf("%-15s%-15d\n", "++a + b--", ++a + b--);
    printf("%-15s%-15d\n", "a", a);
    printf("%-15s%-15d\n", "b", b);
}
