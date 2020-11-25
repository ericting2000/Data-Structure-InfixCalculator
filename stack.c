
#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void init_stack(stack *s) {
    s->top = 0;
}

void push(stack *s, char i) {
    s->elements[s->top] = i;
    s->top++;
}

int pop(stack *s) {
    s->top--;
    return (s->elements[s->top]);
}

bool stack_empty(stack *s) {
    return (s->top <= 0);
}
////
void init_stack_n(S *s) {
    s->top = 0;
}

void push_n(S *s, double a) {
    s->e[s->top] = a;
    s->top++;
}

double pop_n(S *s) {
    s->top--;
    return (s->e[s->top]);
}

bool stack_empty_n(S *s) {
    return (s->top <= 0);
}