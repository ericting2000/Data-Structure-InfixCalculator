#ifndef MAIN_H_
#define MAIN_H_

int check_valid_char(char C);
int check_valid_express(char input[], int len);
char* postfix(char infix[], char postfix[], int len);
int priority(char a);
int calculator(char input[], char post[], int len);

#endif