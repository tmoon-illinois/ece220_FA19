#include <stdio.h>

int main()
{
    char input[10] = "abc";
    scanf("%s", &input[1]);

    printf("%s", input);
}
