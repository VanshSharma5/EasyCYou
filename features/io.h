#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define println(obj) print(obj); \
    printf("\n");


#define UInt32 "uint32"
#define Float "float"

#define set(obj, c_value) \
    if(!strcmp(obj->type, "uint32")) { \
        *(unsigned int*)obj->value = c_value; \
    } \
    else if(!strcmp(obj->type, "float")) { \
        *(float*)obj->value = c_value; \
    }

#define get(type, obj) *(type*)obj->value

typedef struct {
    void* value;
    char* type;
    char* format_specifire;
    ssize_t size;
}var;


var* init(const char* type) {
    var* obj;
    obj = (var*)malloc(sizeof(var));
    
    if(!strcmp(type, "uint32")) {
        obj->value = malloc(sizeof(unsigned int));
        obj->size = sizeof(unsigned int);
        obj->type = "uint32";
        obj->format_specifire = "%u";
    }
    else if(!strcmp(type, "float")) {
        obj->value = malloc(sizeof(float));
        obj->size = sizeof(float);
        obj->type = "float";
        obj->format_specifire = "%f";
    }

    return obj;
}

int input(var *obj, const char* __format, ...) {
    int __retval;
    __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format ); 
    __retval = __mingw_vfprintf( stdout, __format, __local_argv );
    __builtin_va_end( __local_argv );

    scanf(obj->format_specifire, obj->value);
  
    return __retval;
}

int print(var* obj) {
    if(!strcmp(obj->type, "uint32")) {   
        printf(obj->format_specifire, get(unsigned int, obj));
    }
    else if(!strcmp(obj->type, "float")) {   
        printf(obj->format_specifire, get(float, obj));
    }
}
 