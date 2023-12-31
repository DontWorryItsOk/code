#include <stdio.h>

int main() {
    int a = 10;
    int *p_a = &a;
    printf("a = %d\n*p_a = %d\n&a = %d\np_a = %d", a, *p_a, &a, p_a);
    return 0;
}