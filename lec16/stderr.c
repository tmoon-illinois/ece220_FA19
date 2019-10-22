#include <stdio.h>


int main()
{

    fprintf(stdout , "Normal output\n");
    fprintf(stdout , "Normal output\n");
    fprintf(stdout , "Normal output\n");

    fprintf(stderr, "Error \n");
    fprintf(stdout , "Normal output\n");
    fprintf(stdout , "Normal output\n");
    fprintf(stderr, "Warning\n");
    fprintf(stdout , "Normal output\n");
}
