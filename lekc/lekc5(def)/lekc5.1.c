#include <stdio.h>
int global; // переменную можно использовать в любой функции
int minimum(int x, int y) {
    return (x<y)?x:y; //  если х меньше y подставляется значение х, если больше то y
}
    /* if(x<y)
    return x;
    else
    return y; */
    int main() {
        int x, y;
        printf("Введите x и y: ");
        scanf("%d %d", &x, &y);
        printf("%d\n", minimum(x,y));
        // printf("%d\n", minimum(5, -10)); выведет -10, т.к. оно меньше 5
        return 0;

    }