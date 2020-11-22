#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int check;
    char input[50], a, b;
    printf("Please enter an infix expression and press enter:\n");
    scanf("%s", input);
    check = strlen(input);
    printf("%d\n", check);
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
        return main();
    }
    printf("%s\n", input);
    return 0;
}