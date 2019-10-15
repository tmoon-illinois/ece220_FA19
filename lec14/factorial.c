#include <stdio.h>

int Factorial_iter(int n);//n!
int Factorial(int n);//n!
int main(){
    int n;

    printf("Input n:");
    scanf("%d", &n);

    printf("Iter: Factorial %d = %d\n", n, Factorial_iter(n));
    printf("Recur: Factorial %d = %d\n", n, Factorial(n));
}


int Factorial(int n){//n!
    if(n==1)
        return 1;
    else
        return n*Factorial(n-1);
}

int Factorial_iter(int n){//n!
    int i;
    int fn=1;
    for(i=1;i<=n;i++)
        fn = fn * i;

    return fn;
}
