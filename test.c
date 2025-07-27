#include"features/io.h"

int main() {
    Int a = int_input("Enter a number :");
    Double b = double_input("Enter a number :");
    Float c = float_input("Enter a number :");
    printf("%d\t%lf\t%f", *a, *b, *c);
}
