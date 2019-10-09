#include <stdio.h>
#include <string.h>

void string_copy(char des[], char const src[]);
int main()
{
    char buf[200];// ="ABCD";

    //buf = "ABCD";
    //string_copy(buf, "ABC");
    
    strcpy(buf, "ABC");
    printf("%s\n", buf);
}
void string_copy(char des[], char const src[])
{
    int i=0;
    //src[0] = '\0';

    while(src[i]!= '\0' )
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
}
