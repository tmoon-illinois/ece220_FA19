#include <stdio.h>

typedef enum weekday {SUN=12, MON=10, TUE, WED} WEEKDAY;
int main(){
    WEEKDAY day;
    day = WED;
    printf("%d\n", day);
}
