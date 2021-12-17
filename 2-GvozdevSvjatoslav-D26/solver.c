#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include "math.h"

#define OPERATIONS 4
#define NUM_CHAR_BUFF_SIZE 300

// 0='+' 1='-' 2='*' 3='/'




void print_ans(char* str, char operator, long long val){
    char ans[NUM_CHAR_BUFF_SIZE] = {0};
    sprintf(ans, "%c%i", operator, val);
    char* ans_cursor = ans;
    for (;*ans_cursor != '\0'; *str++ = *ans_cursor++);
}
static int __solver(char* str, long long result, long long value, long long last_val, int first_iter_flag, char* ans){
    if (strlen(str) == 0)
        return value + last_val;

    for ( long long i = 1 + ((first_iter_flag && *str == '-') ? 1 : 0); i <= strlen(str); i++){
        long long val;
        char buf[NUM_CHAR_BUFF_SIZE] = {0};
        char* copy_pointer = buf;
        char* copy_pointer2 = str;

        for (int k = 0; k < i; k++)
            *copy_pointer++ = *copy_pointer2++;

        sscanf(buf, "%ld", &val);


        for (int k = 0; k < OPERATIONS; k++){
            int operator = k;
            if (first_iter_flag){
                operator = 0;
            }

            switch (operator){
                case 0:
                    if (__solver(str + i, result, value + last_val, val, 0, ans + i + 1) == result){
                        print_ans(ans, '+', val);
                        return result;
                    }
                    break;

                case 1:
                    if (__solver(str + i, result, value + last_val, -val, 0,ans + i + 1) == result){
                        print_ans(ans, '-', val);
                        return result;
                    }
                    break;

                case 2:
                    if (__solver(str + i, result, value, last_val * val, 0,ans + i + 1) == result){
                        print_ans(ans, '*', val);
                        return result;
                    }
                    break;

                case 3:
                    if(val!=0){
                        if ((last_val % val == 0) && (__solver(str + i, result, value, last_val / val, 0,ans + i + 1) == result)){
                            print_ans(ans, '/', val);
                            return result;
                        }
                        break;
                    }}
        }
    }
    return 0;
}



void solver(long long input, long long result, char* ans){
    char data[NUM_CHAR_BUFF_SIZE] = {0};
    sprintf(data, "%lld", input);
    if (__solver(data, result, 0, 0, 1, ans) == result)
        memcpy(ans, ans + 1, strlen(ans));
    else
        sprintf(ans, "%d", 0);
}


