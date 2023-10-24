#include <stdio.h>
int main() {
    int t, S;
    S=0;
    printf("Введите число: ");
    scanf("%d", &t);
    while(t != 0) // while(t)
{
    S += t;
    printf("еще ");
    scanf("%d", &t);
}
printf("Сумма = %d", S);

return 0;
}
/*
    int tmp;
    tmp = ar[2];
    ar[2] = ar[0];
    ar[0] = tmp;
*/

