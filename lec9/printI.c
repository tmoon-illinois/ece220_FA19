#include <stdio.h>

int main(){
    int i,j;
    int n=3;
    for(i=0;i<n;i++)
    {
        for(j=0; j<n; j++){
            if(i==1 && j==2)
                return 0;
            if(i==j)
                printf("1 ");
            else
                printf("0 ");

        }
        printf("\n");
    }

}
