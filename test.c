#include<stdio.h>
#include"features/io.h"

int main() {
    String name = input("Enter Your Name :<MAX-16>", 16);
    Int age = inputInt("Enter Your Age :");
    String gender = input("Enter Your Gender<Male/Female", 8);

    println("The Details You Give Are");
    print(name);
    printInt(age);
    print(gender);

    return 0;
}
