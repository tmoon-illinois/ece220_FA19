#include <stdio.h>

int main()
{
    int itsLocal = 1;
    {
        int itsLocal = 2;
        printf("%d\n", itsLocal);
    }
        printf("%d\n", itsLocal);


        return 0;
}
