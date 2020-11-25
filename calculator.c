#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "stack.h"

int calculator(char input[], char post[], int len) {
    int stat1 = 0, stat2 = 0, k = 0, r = 0, q = 0, n = 0, cnt_digit_num = 0, temp = 0, cnt_digit_op = 0, len_p;
    int c[2][20] = {}, o[2][20] = {};  //create a board to record the multidigit nums
    double a1, a2, ans;
    S s = {};
    postfix(input, post, len);
    len_p = strlen(post);
    //printf("len = %d\n", len);
    for (int i = 0; i < len; i++) {
        if (isdigit(input[i])) {
            if (stat1 == 0) {
                //printf("input[%d] is now %d\n", i, input[i] - '0');
                stat1 = 1;
                temp = temp * 1 + (input[i] - '0');
                cnt_digit_num++;
            } else {
                //printf("input[%d] is now %d\n", i, input[i] - '0');
                temp = temp * 10 + (input[i] - '0');
                cnt_digit_num++;
            }
        } else {
            stat1 = 0;
            if (temp != 0 && cnt_digit_num != 0) {
                c[0][k] = temp;
                c[1][k] = cnt_digit_num;
                temp = 0;
                cnt_digit_num = 0;
                k++;
            }
        }
        if (i == len - 1 && stat1 == 1) {
            c[0][k] = temp;
            c[1][k] = cnt_digit_num;
            temp = 0;
            cnt_digit_num = 0;
            k++;
        }
    }
    for (int i = 0; i < len_p; i++) {
        if (!isdigit(post[i])) {
            if (stat2 == 0) {
                stat2 = 1;
                o[0][r] = i;
                cnt_digit_op++;
            } else {
                cnt_digit_op++;
            }
        } else {
            stat2 = 0;
            if (cnt_digit_op != 0) {
                o[1][r] = cnt_digit_op;
                cnt_digit_op = 0;
                r++;
            }
        }
        if (i == len_p - 1 && stat2 == 1) {
            o[1][r] = cnt_digit_op;
            cnt_digit_op = 0;
            r++;
        }
    }
    /*for (int i = 0; i < r; i++) {
        printf("o[0][%d] = %d\n", i, o[0][i]);
        printf("o[1][%d] = %d\n", i, o[1][i]);
    }*/
    ///evaluate postfix expression
    int j = 0;
    while (j < len_p) {
        //printf("j = %d\n", j);
        if (j != o[0][q]) {
            //printf("c[0][%d] = %d\n", n, c[0][n]);
            push_n(&s, c[0][n]);
            j += c[1][n];
            n++;
        } else {
            //printf("check\n");
            for (int i = 0; i < o[1][q]; i++) {
                a2 = pop_n(&s);
                a1 = pop_n(&s);
                //printf("a2 = %f\n", a2);
                //printf("a1 = %f\n", a1);
                switch (post[j]) {
                    case '+':
                        ans = a1 + a2;
                        //printf("ans = %f\n", ans);
                        push_n(&s, ans);
                        break;
                    case '-':
                        ans = a1 - a2;
                        //printf("ans = %f\n", ans);
                        push_n(&s, ans);
                        break;
                    case '*':
                        ans = a1 * a2;
                        //printf("ans = %f\n", ans);
                        push_n(&s, ans);
                        break;
                    case '/':
                        ans = a1 / a2;
                        //printf("ans = %f\n", ans);
                        push_n(&s, ans);
                        break;
                }
                j++;
            }
            q++;
        }
    }
    ans = pop_n(&s);
    //printf("ans = %f\n", ans);
    if ((int)ans == ans)
        printf("= %d\n", (int)ans);
    else {
        printf("= %.2f\n", ans);
    }
    return 0;
}