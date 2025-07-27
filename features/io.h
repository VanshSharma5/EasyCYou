#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"datatypes.h"

/*
 * The set of function are use to print the individual variable value
*/
int printInt(Int variable) {
    return printf("%d", *variable);
}

int printFloat(Float variable) {
    return printf("%f", *variable);
}

int printDouble(Double variable) {
    return printf("%lf", *variable);
}

int printBoolean(Boolean variable) {
    return printf("%s", variable == True?"True":"False");
}

int print(String str) {
    return printf("%s", str);
}

int println(String str) {
    return printf("%s\n", str);
}

void prints(int count, char sep, ...) {
    va_list args;
    va_start(args, count); 

    for (int i = 0; i < count; i++) {
        printf("%s%c", (va_arg(args, String)), sep);
    }
    va_end(args); 
}

/* 
 * It contains the Simpler function to Take user Input at Runtime (Dynamicaly)   
*/
Int inputInt(String prompt) {
    printf(prompt);
    Int temp = (int*)malloc(sizeof(int));
    scanf("%d", temp);
    return temp;
} 

Double inputDouble(String prompt) {
    printf(prompt);
    Double temp = (double*)malloc(sizeof(double));
    scanf("%lf", temp);
    return temp;
}

Float inputFloat(String prompt) {
    printf(prompt);
    Float temp = (float*)malloc(sizeof(float));
    scanf("%f", temp);
    return temp;
}

Boolean inputBoolean(String prompt) {
    printf(prompt);
    int temp; 
    scanf("%d", &temp);
    return temp?True:False;
}

String input(String prompt, size_t max_size) {
    fflush(stdin);
    printf(prompt);
    String temp = (String)malloc((size_t)max_size);
    scanf("%[^\n]s", temp);
    return temp;
}


/*
 * These functions are use to parse the Modified Data types
 */


/*
 * This function is use to de-allocate the memory occupies by the variables
 */

 void frees(int count, ...) {
    va_list args;
    va_start(args, count); 

    for (int i = 0; i < count; i++) {
        free(va_arg(args, void*));
    }
    va_end(args); 
 }

 