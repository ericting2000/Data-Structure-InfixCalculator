#include "main.h"

void init_stack(stack *s){
    s->top = 0;
}

int stack_full(stack *s){
    return (s->top >= 100);
}

int stack_empty(stack *s){
    return (s->top <= 0);
}

void push(stack *s, char i){
    if (stack_full(s)) {
        printf("stack is full\n");
        return;
    }
    s->elements[s->top] = i;
    s->top++;
}

int pop_stack(stack *s){
    if (stack_empty(s)) {
        printf("stack is empty\n");
        return (-1);
    }
    s->top--;
    return (s->elements[s->top]);
}