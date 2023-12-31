#include <stdio.h>

int main() {
    int x;
    int *px;
    x=5;
    px=&x;

    printf("%d\n", x);
    printf("%d\n", *px);
    printf("%d\n", &x);
    printf("%d\n", px);
}