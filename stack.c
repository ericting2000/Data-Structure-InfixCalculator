#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init_stack(stack *s){
    s->top = 0;
}

void push(stack *s, char i){
    s->elements[s->top] = i;
    s->top++;
}

int pop_stack(stack *s){
    s->top--;
    return(s->elements[s->top]);
}