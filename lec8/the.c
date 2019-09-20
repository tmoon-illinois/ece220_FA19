#include <stdio.h>

#define NO_MATCH 0
#define MATCH_t 1
#define MATCH_th 2
int main()
{

    int counter = 0;
    int state = NO_MATCH;
    char keyin;//input form keyboard
    printf("ENter a string:\n");

    do{
        scanf("%c", &keyin);
        switch(state){
        case NO_MATCH:
            if(keyin == 't'){
                state = MATCH_t;
            }
            break;
        case MATCH_t:
            if(keyin == 'h'){
                state = MATCH_th;
            }
            else if (keyin =='t'){
                state = MATCH_t;
            }
            else{
                state = NO_MATCH;
            }
            break;
        case MATCH_th:
            if(keyin == 'e'){
                state = NO_MATCH;
                counter ++;
            }
            else if (keyin =='t'){
                state = MATCH_t;
            }
            else{
                state = NO_MATCH;
            }
            break;
        default:
            printf("Not valid state\n");
            return 0;
        }

    }while(keyin != '\n');
    printf("Number of 'the' is %d\n", counter);


    return 0;

}
