#include <stdio.h>

#define BUF_SIZE 2
int main(){
    char buf_before[4]="ABC";
    char buf[BUF_SIZE];
    char buf_after[4]="EFG";

    printf("%p\n", buf_before);
    printf("%p\n", buf);
    printf("%p\n", buf_after);
    scanf("%s", buf);
    //fgets(buf, BUF_SIZE, stdin);

    printf("buf_before = %s\n", buf_before);
    printf("buf= %s\n", buf);
    printf("buf_after= %s\n", buf_after);

}
