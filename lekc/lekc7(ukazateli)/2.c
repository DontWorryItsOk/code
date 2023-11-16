#include <stdio.h>
int main() {
    int x, *p, **g;
    x=10;
    p=&x;
    g=&p;
    printf("x=%d\n", x);
    printf("*p=%d\n", *p);
    printf("**g=%d\n", **g);
}
