#include <stdio.h>
#include <math.h>


int main()
{
    float a,b,c;
    float D;
    float x1, x2;

    printf("Enter a, b, c:");
    scanf("%f, %f, %f", &a, &b, &c);

    printf("%f*x^2 + %f*x + %f =0\n", a, b, c);

    D = b*b - 4*a*c;

    if(D==0){
        x1 = -b/(2*a);
        printf("one real root x = %f\n", x1);
    }
    else if (D > 0){
        x1 = (-b+sqrt(D))/(2*a);
        x2 = (-b-sqrt(D))/(2*a);
        printf("two real root x1 = %f, x2 = %f\n", x1, x2);
    }
    else{//D < 0
        printf("no real root\n");
    }

    return 0;

}
