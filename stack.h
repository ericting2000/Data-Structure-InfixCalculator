typedef struct{
    int top;
    char elements[50];
}stack;

void init_stack(stack *s);
void push(stack *s, char c);
int pop(stack *s);