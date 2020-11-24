#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "stack.c"

int priority(char a) {
    if (a == '(')
        return 0;
    if (a == '*' || a == '/')
        return 2;
    if (a == '+' || a == '-')
        return 1;
    return -1;
}

void postfix(char infix[], int len) {
    //printf("check in postfix\n");
    stack s = {};
    char postfix[50];
    int k = 0;
    init_stack(&s);
    //printf("top = %d\n", s.top);
    for (int i = 0; i < len; i++) {
        //printf("i = %d\n", i);
        if (isdigit(infix[i])) {
            //printf("check1\n");
            postfix[k++] = infix[i];
        }
        if (infix[i] == '(') {
            //printf("check2\n");
            push(&s, infix[i]);
            //printf("top = %d\n", s.top);
        }
        if (infix[i] == ')') {
            //printf("check3\n");
            //printf("s.element[%d] = %c\n", 0, s.elements[0]);
            while (s.elements[s.top - 1] != '(') {
                //printf("top = %d\n", s.top);
                //printf("%c\n", s.elements[s.top]);
                postfix[k++] = pop(&s);
            }
            pop(&s);
            //printf("1111\n");
        }
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            //printf("check4\n");
            //printf("%d\n", priority(s.elements[s.top]));
            while (priority(s.elements[s.top - 1]) >= priority(infix[i])) {
                //printf("top = %d\n", s.top);
                //printf("check while loop\n");
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
            //printf("top = %d\n", s.top);
        }
        //printf("postfix[%d] = %c\n", k - 1, postfix[k - 1]);
        //printf("k = %d\n", k);
    }
    while (s.top != -1)
        postfix[k++] = pop(&s);
    postfix[k - 1] = '\0';
    printf("The postfix expression: %s\n", postfix);
    //return &postfix;
}