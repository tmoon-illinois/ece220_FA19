#include <stdio.h>

int main()
{
    /*
    char grid[10];
    char x;

    printf("&grid[0] = %u\n", &grid[0]); 
    printf("&grid[1] = %u\n", &grid[1]); 
    printf("&grid[9] = %u\n", &grid[9]); 
    printf("&x = %u\n",&x); 
*/

    //char word[10];
    //char *cptr;

    int word[10];
    int *cptr;
    
    word[0] = 'a';
    word[1] = 'b';
    word[2] = 'c';
    word[3] = 'd';

    cptr = word; // cptr = &word[0]

    printf("cptr = %u\n", cptr);
    printf("word= %u\n", word);
    printf("addr of word[0]= %u\n", &word[0]);
    
    printf("cptr +1 = %u\n", cptr+1);
    printf("word +1 = %u\n", word+1);
    printf("addr of word[1]= %u\n", &word[1]);
    printf("value of word[1]= %c\n", *(cptr+1));
}
