#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

double GenRand(double a, double b);
int main(){
/*
    srand(time(0));

    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
*/
    printf("RAND_MAX = %d\n", RAND_MAX);


    double a, b;
    printf("Enter a,b (range)" );
    scanf("%lf %lf", &a, &b);

    unsigned int n;
    printf("Enter n (number of samples)" );
    scanf("%u", &n);


    unsigned int seed;
    printf("Enter seed: " );
    scanf("%u", &seed);
    srand(seed);


    double mean_th, var_th;
    mean_th = (b+a)/2;
    var_th = (b-a)*(b-a)/12;

    double x;
    double mean_s=0, var_s=0;
    int k;
    for(k=0; k<n;k++)
    {
        x = GenRand(a, b);
        mean_s = mean_s + x;
        var_s = var_s + x*x;


    }
    mean_s = mean_s/n;
    var_s = var_s/n - mean_s*mean_s;

    printf("Theoretical mean, variance: %lf, %lf\n", mean_th, var_th);
    printf("Sample mean, variance: %lf, %lf\n", mean_s, var_s);




}
double GenRand(double a, double b)
{
    int num = rand();
    double result;

    result = num*(b-a)/RAND_MAX + a;// result is between a and b

    return result;
}
