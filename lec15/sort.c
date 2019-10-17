#include <stdio.h>
void print_array(int array[], int n);
void swap(int *firstVal, int *secondVal);
void bubbleSort(int array[], int n);
void insertSort(int array[], int n);
void quickSort(int array[], int low, int high);
#define SIZE 7

int main()
{
    //int array[SIZE] = {64, 34, 25, 12, 22, 11, 1};
//    int array[SIZE] = {5, 1, 4, 2, 8};
    int array[SIZE] = {50, 80, 30, 90, 40, 10, 70};

    printf("Before sort: ");
    print_array(array, SIZE);
    //bubbleSort(array, SIZE);
    //insertSort(array, SIZE);
    quickSort(array, 0, SIZE-1);
    printf("After sort: ");
    print_array(array, SIZE);

}
void print_array(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}
void swap(int *firstVal, int *secondVal)
{
    int tempVal;

    tempVal = *firstVal;
    *firstVal = *secondVal;
    *secondVal = tempVal;
}
void bubbleSort(int array[], int n)
{
    int is_swapped;

    int i;
    do{
        is_swapped = 0;
        for(i=0; i< n-1; i++){
            if( array[i] > array[i+1]){
                swap(&array[i], &array[i+1]);
                is_swapped = 1;
            }
        }
    }while(is_swapped == 1);

}
void insertSort(int array[], int n)
{
    int unsorted, sorted;
    int unsortedItem;

    for(unsorted = 1;unsorted < n ;unsorted++)
    {
        unsortedItem = array[unsorted]; // Store the green value
        for(sorted = unsorted-1;  (sorted >= 0) && (unsortedItem < array[sorted]) ; sorted--)
        {
            array[sorted +1] = array[sorted];
        }
        array[sorted+1] = unsortedItem;
    }

}

void quickSort(int array[], int low, int high)
{
    //base case

    if(low >= high)
        return;

    //recursive case
    int pivot_index = partition();
    quickSort(array, low , pivot_index-1 );// first half
    quickSort(array, pivot_index+1 , high );//second half
}

// partition: returing the pivot index
int partition(int array[], int low, int high)
{
    int pivot = array[high]; //set the last element as pivot
    int i = low - 1; // index of smaller element
    int j;
    for(j=low;j<=high-1;j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[i+1], &array[high]);

    printf("partition) Partitioned array: ");
    print_array(array, SIZE);
    printf("partition) pivot index : %d\n", i+1);

    return i+1;
}


