#include  <stdio.h>

void array_reverse(int array[], int n);
void print_array(int array[], int n);

int main()
{
    int n;

    printf("Enter the size of array :");
    scanf("%d", &n);

    int array[n];
    printf("Enter each element\n");
    int i;
    for(i = 0;i < n; i++){
        printf("Input %d-th element:", i);
        scanf("%d", &array[i]);
    }

    printf("Before reverse\n");
    print_array(array, n);

    printf("After reverse\n");
    array_reverse(array, n);
    print_array(array, n);

    
}
void array_reverse(int array[], int n)
{
    int i;
    int temp;
    for(i = 0;i < n/2; i++){
        temp = array[i];
        array[i] = array[n-i-1]; //i=0,n=4, array[0] = array[3]
        array[n-i-1] = temp;
    }

}
void print_array(int array[], int n)
{
    int i;
    for(i = 0;i < n; i++){
        printf("%d  ", array[i]);
    }

    printf("\n");
}
