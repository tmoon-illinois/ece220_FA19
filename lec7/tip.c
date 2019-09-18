#include <stdio.h>

#define TIP 0.18

int main()
{
    float total=0 , bill=0;

    printf("Enter your bill amount: ");
    scanf("%f", &bill);

    total = bill*(1+TIP);

    printf("The total is %.2f\n", total);
}
