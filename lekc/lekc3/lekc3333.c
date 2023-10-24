#include <stdio.h>
int main() {
    int t, S;
    S=0;
    printf("Введите число: ");
    scanf("%d", &t);
    while(1) {
    S += t;
    printf("еще ");
    scanf("%d", &t);
    if(t == 0) break;
    }
    printf("Сумма = %d", S);

return 0;
}
