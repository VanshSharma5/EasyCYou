#define TYPE_OF(x) _Generic((x), \
    int*: "Int", \
    float*: "Float", \
    double*: "Double", \
    char: "Char", \
    char*: "String", \
    default: "unknown type" \
)

typedef enum {
    False = 0, True = 1
} Boolean;

typedef int* Int;
typedef double* Double;
typedef float* Float;
typedef char Char;
typedef char* String;
