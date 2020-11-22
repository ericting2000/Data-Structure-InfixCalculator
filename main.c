#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stack.c"
#include "postfix.c"
#include "calculator.c"

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

int main(){
    int check, valid = 0;
    char input[50], a, b;
    printf("Please enter an infix expression and press enter:\n");
    while(scanf("%s", input) == 1){
        int tap1 = 0;
        check = strlen(input);
        if(check > 20){
            printf("Error - line contains more characters than allowed.\n");
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
            tap1 = 1;
        }
        if(tap1 != 1){
            for(int i = 0; i < check; i++){
            valid = check_valid(input[i]);
            if(valid == 1)
                continue;
            }
        }
        printf("Please enter an infix expression and press enter:\n");
    }
    return 0;
}