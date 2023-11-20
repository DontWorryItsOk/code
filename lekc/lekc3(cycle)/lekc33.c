#include <stdio.h>
int main() {
    int t, S;
   for (printf("Введите число: "), S = 0; scanf("%d", &t), t; S += t, printf("еще "));
   printf("Сумма = %d", S);

   return 0;
}
