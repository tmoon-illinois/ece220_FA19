#include <stdio.h>
typedef struct flightType{
    int altitude;
}Flight;


int main()
{
    /*
    struct aaa AAA = {1, 2};
 //   AAA.a1 = 0;
   // AAA.a2 = 1;

    printf("a1: %d, a2: %d\n", AAA.a1, AAA.a2);
    */

    Flight planes[100];
    Flight *ptr1,*ptr2;

    ptr1 = &planes[1];
    ptr2 = planes;
    
    ptr1->altitude = 10000;
    ptr2->altitude = 20000;

    ptr2++;// point second one

    printf("%d\n", planes[1].altitude);
    printf("%d\n", ptr2->altitude);

    planes[2].altitude = 300000;
    ptr1++;
    printf("%d\n", planes[2].altitude);
    printf("%d\n", ptr1->altitude);

    printf("%d\n", planes->altitude);// valid

    ptr1 = ptr1 +1;
//    planes = planes  +2;  //compile error
}
