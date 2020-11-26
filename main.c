#include "main.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator.c"
#include "check.c"
#include "postfix.c"
#include "stack.c"

void esc_to_exit() {
    char a, b;
    printf("Press esc to quit or enter to continue.\n");
    scanf("%c", &a);
    system("stty -icanon");
    system("stty -echo");
    b = getchar();
    system("stty icanon");
    system("stty echo");
    if (b == 27) exit(0);
    system("clear");
}

int main() {
    int len;
    char input[50], postfix[50], a, b;
    printf("Please enter an infix expression and press enter:\n");
    while (scanf("%s", input) == 1) {
        int valid1 = 0, valid2 = 0;
        int tap1 = 0, tap2 = 0;
        len = 0;
        len = strlen(input);
        if (len > 20) {
            printf("Error - line contains more characters than allowed.\n");
            esc_to_exit();
            tap1 = 1;
        }
        if (tap1 != 1) {
            for (int i = 0; i < len; i++) {
                valid1 = check_valid_char(input[i]);
                //if (valid1 == 1) continue;
            }
            check = 0;
            valid2 = check_valid_express(input, len);
            if (valid1 == 1 || valid2 == 1) {
                esc_to_exit();
            } else {
                calculator(input, postfix, len);
                esc_to_exit();
            }
        }
        printf("Please enter an infix expression and press enter:\n");
    }
    return 0;
}