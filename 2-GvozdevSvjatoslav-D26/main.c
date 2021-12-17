#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include "math.h"

#include "solver.h"


/*
 * CPU: Intel(R) Core(TM) i3 M 370 2.40 GHz
 * RAM: 4097 MB
 * SSD: 110 GB
 *
 * Test results(2683938195591,71234) (All options)
 *      Stress Test results:
 *      Memory: 340 MB
 *      Solver execution time: 63.275 seconds
 *
 *
 */





void stress_test(FILE* f_input, FILE* f_output){
    int value;
//    fprintf(f_input,"%lld",26839381955912);
//    fprintf(f_input,"\n");
//    fprintf(f_input, "%lld",71234);
    fprintf(f_input,"%lld",2683938195591);
    fprintf(f_input,"\n");
    fprintf(f_input, "%lld",71234);
    char ans[600] = {0};
    char* p = ans;
    char* str;
    long long val, val2;
    fseek(f_input,0,SEEK_SET);
    fscanf(f_input,"%lld %lld",&val, &val2);
    unsigned long start = clock();
    solver(val, val2, ans);
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    fprintf(f_output,"%s", ans);
    printf("%f\n", time);

}








int main(){
    FILE* f_input = fopen("C:\\Users\\user\\CLionProjects\\untitled10\\input.txt", "r+");
    FILE* f_output = fopen("C:\\Users\\user\\CLionProjects\\untitled10\\output.txt","w");
    if ((f_input != NULL) && (f_output != NULL)){
//    char ans[600] = {0};
//    char* p = ans;
//    char* str;
//    long long val, val2;
//    fscanf(f_input,"%lld %lld",&val, &val2);
//    solver(val, val2, ans);
//    fprintf(f_output,"%s", ans);
    stress_test(f_input,f_output);
    return 0;}
    else {return 1;}
}