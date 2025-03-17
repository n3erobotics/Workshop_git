#include <stdio.h>

#include "libs/lib1.h"
#include "libs/libs_alt/lib2.h"

int main() {
    int value;

    printf("Give me a number\n> ");
    scanf("%d", &value);

    printf("The square of %d is: %d\n", value, square(value));
    printf("The factorial of %d is: %d\n", value, factorial(value));

    return 0;
}
