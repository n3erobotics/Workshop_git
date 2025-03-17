int factorial(int value) {
    int result = 1;
    int i;

    for (i = 2; i <= value; ++i) {
        result *= i;
    }

    return result;
}
