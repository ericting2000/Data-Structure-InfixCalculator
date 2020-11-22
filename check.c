#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

int check_valid(char C){
    char a, b;
    switch(C){
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':case '8': case '9': case '(': case ')': case '+': case '-': case '*': case '/':
            break;
        default:{
            printf("Illegal character\n");
            printf("Press esc to quit or any other key to continue.\n");
            scanf("%c", &a);
            system("stty -icanon");
            system("stty -echo");
            b=getchar();
            system("stty icanon");
            system("stty echo");
            if(b == 27)
                exit(0);
            system("clear");
            return 1;
        }
    }
    return 0;
}