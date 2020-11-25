#ifndef STACK_H_
#define STACK_H_

typedef struct {
    int top;
    char elements[50];
} stack;

typedef struct {
    int top;
    double e[50];
} S;

void init_stack(stack *s);
bool stack_empty(stack *s);
void push(stack *s, char c);
int pop(stack *s);

void init_stack_n(S *s);
bool stack_empty_n(S *s);
void push_n(S *s, double a);
double pop_n(S *s);

#endif