#include <stdio.h>
#include<stdlib.h>
#include<string.h>

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
    ssize_t size;
}var;


var* init(const char* type) {
    var* obj;
    obj = (var*)malloc(sizeof(var));
    
    if(!strcmp(type, "uint32")) {
        obj->value = malloc(sizeof(unsigned int));
        obj->size = sizeof(unsigned int);
        obj->type = "uint32";
    }
    else if(!strcmp(type, "float")) {
        obj->value = malloc(sizeof(float));
        obj->size = sizeof(float);
        obj->type = "float";
    }

    return obj;
}
 