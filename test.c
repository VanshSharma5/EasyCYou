#include"features/io.h"

int main() {

    var* num = init(Float);
    set(num, -1);
    //input(int, num, "Enter a number :");
    printf("%f", get(float, num));
    printf("%s", num->type);
    return 0;
}