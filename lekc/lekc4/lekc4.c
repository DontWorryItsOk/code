// программа выводит число в обратном порядке
#include <stdio.h>
int main() {
    int number;
    printf("Введите число: ");
    scanf("%d", &number);
    while(number) { // number не равно 0
        printf("%d",number%10);
        number /= 10;
    }
    return 0;
}
