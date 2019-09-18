/*
 * Program Name: countdown
 */
// Preprocessor directives
#include <stdio.h>
#define STOP 0

// Main function
int main()
{
    // Variable declaration
    int counter;
    int startPoint;

    // I/O
    printf("Enter a positive integer: ");
    scanf("%d", &startPoint);

    // Count down from the input number to 0
    for(counter = startPoint; counter >= STOP; counter--)
    {
        printf("%d\n", counter);
    }

    // Return value
    return 0;
}
