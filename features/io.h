#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define println(obj) print(obj); \
    printf("\n");

#define UInt32 "uint32", 1
#define Float "float", 1
#define String(size) "string", size

#define set(obj, c_value) \
    if(!strcmp(obj->type, "uint32")) { \
        *(unsigned int*)obj->value = c_value; \
    } \
    else if(!strcmp(obj->type, "float")) { \
        *(float*)obj->value = c_value; \
    }

#define get(type, obj) *(type*)obj->value

typedef char* string;
typedef struct {
    void* value;
    char* type;
    char* format_specifire;
    size_t len;
    ssize_t size;
}var;


var* Init(const char* type, int max_size) {
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
    else if(!strcmp(type, "string")) {
        obj->value = malloc(sizeof(char)*max_size);
        obj->size = max_size;
        obj->len = 0;
        obj->type = "string";
        obj->format_specifire = "%s";
    }

    return obj;
}

int input(var *obj, const char* __format, ...) {
    int __retval;
    __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format ); 
    __retval = __mingw_vfprintf( stdout, __format, __local_argv );
    __builtin_va_end( __local_argv );
    if(!strcmp(obj->type, "string")) {
        scanf("%[^\n]s", obj->value);
    } else {   
        scanf(obj->format_specifire, obj->value);
    }
  
    return __retval;
}

int print(var* obj) {
    fflush(stdin);
    if(!strcmp(obj->type, "uint32")) {   
        printf(obj->format_specifire, *(unsigned int*)obj->value);
    }
    else if(!strcmp(obj->type, "float")) {   
        printf(obj->format_specifire, *(float*)obj->value);
    }
    else if(!strcmp(obj->type, "string")) {   
        printf(obj->format_specifire, (string)obj->value);
    }
}
 