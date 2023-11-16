#include <stdio.h>
int main() {
    int t, S;
    S = 0;
    printf("Введите число: ");
    do {
        scanf("%d", &t);
        S += t;
    printf("еще ");
    }
    while (t!= 0);
    printf("Сумма = %d", S);

    return 0;
}
