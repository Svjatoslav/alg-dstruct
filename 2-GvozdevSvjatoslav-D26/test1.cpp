#include "gtest/gtest.h"
extern "C" {
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "math.h"

#define OPERATIONS 4
#define NUM_CHAR_BUFF_SIZE 300

// 0='+' 1='-' 2='*' 3='/'




void print_ans(char *str, char operator1, long long val) {
    char ans[NUM_CHAR_BUFF_SIZE] = {0};
    sprintf(ans, "%c%i", operator1,
    val);
    char *ans_cursor = ans;
    for (; *ans_cursor != '\0'; *str++ = *ans_cursor++);
}
static int __solver(char *str, long long result, long long value, long long last_val, int first_iter_flag, char *ans) {
    if (strlen(str) == 0)
        return value + last_val;

    for (long long i = 1 + ((first_iter_flag && *str == '-') ? 1 : 0); i <= strlen(str); i++) {
        long long val;
        char buf[NUM_CHAR_BUFF_SIZE] = {0};
        char *copy_pointer = buf;
        char *copy_pointer2 = str;

        for (int k = 0; k < i; k++)
            *copy_pointer++ = *copy_pointer2++;

        sscanf(buf, "%ld", &val);


        for (int k = 0; k < OPERATIONS; k++) {
            int operator1 = k;
            if (first_iter_flag) {
                operator1=0;
            }

            switch (operator1){
                    case 0:
                    if (__solver(str + i, result, value + last_val, val, 0, ans + i + 1) == result){
                        print_ans(ans, '+', val);
                        return result;
                    }
                    break;

                    case 1:
                    if (__solver(str + i, result, value + last_val, -val, 0, ans + i + 1) == result){
                        print_ans(ans, '-', val);
                        return result;
                    }
                    break;

                    case 2:
                    if (__solver(str + i, result, value, last_val * val, 0, ans + i + 1) == result){
                        print_ans(ans, '*', val);
                        return result;
                    }
                    break;

                    case 3:
                    if (val!=0){
                        if ((last_val % val == 0) &&
                            (__solver(str + i, result, value, last_val / val, 0, ans + i + 1) == result)) {
                            print_ans(ans, '/', val);
                            return result;
                        }
                        break;
                    }}
        }
    }
    return 0;
}


void solver(long long input, long long result, char *ans) {
    char data[NUM_CHAR_BUFF_SIZE] = {0};
    sprintf(data, "%lld", input);
    if (__solver(data, result, 0, 0, 1, ans) == result)
        memcpy(ans, ans + 1, strlen(ans));
    else
        sprintf(ans, "%d", 0);
}
}



TEST(solver,test1){
    char ans[100]={0};
    solver(1, 1, ans);
    ASSERT_EQ(strcmp(ans,"1"),0);


}

TEST(solver,test2){
    char ans[100]={0};
    solver(1234,10,ans);
    ASSERT_EQ(strcmp(ans,"1+2+3+4"),0);


}
TEST(solver,test3){
    char ans[100]={0};
    solver(0,0,ans);
    ASSERT_EQ(strcmp(ans,"0"),0);
}

TEST(solver, test4){
    char ans[100]={0};
    solver(123456789,1234,ans);
    ASSERT_EQ(strcmp(ans,"1+234*5+6*7-8+9"), 0);
}

TEST(solver, test5){
    char ans[100]={0};
    solver(10000,1,ans);
    ASSERT_EQ(strcmp(ans,"1+0+0+0+0"),0);
}

TEST(solver,test6){
    char ans[100]={0};
    solver(123,100,ans);
    ASSERT_EQ(strcmp(ans,"0"),0);
}
