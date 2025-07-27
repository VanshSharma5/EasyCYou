#include<stdio.h>
#include<stdlib.h>

typedef int* Int;
typedef double* Double;
typedef float* Float;
typedef char Char;


Int int_input(const char* prompth) {
    printf(prompth);
    Int temp = (int*)malloc(sizeof(int));
    scanf("%d", temp);
    return temp;
} 

Double double_input(const char* prompth) {
    printf(prompth);
    Double temp = (double*)malloc(sizeof(double));
    scanf("%lf", temp);
    return temp;
}

Float float_input(const char* prompth) {
    printf(prompth);
    Float temp = (float*)malloc(sizeof(float));
    scanf("%f", temp);
    return temp;
}


