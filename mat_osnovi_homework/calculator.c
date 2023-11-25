/* Написать калькулятор для целых чисел. Операнды и результат
могут быть заданы в разных системах счисления.
Требования:
1. оконный интерфейс;
2. контроль вводимых значений. 

1 операнд - 16
2 операнд - 2 
результат - 2 */

#include <stdio.h>
#include <string.h>
#include <math.h>


void dvoichn_in_des(char second[50], int *p_des) {
    int length = strlen(second);
    int des = 0, i = 0;
    for (i = 0; i < 50; i++) {
        if (second[i] == '1') {
            des += 1 * pow(2, length - i - 1);
        }
    }
    *p_des = des;  // Сохраняем значение des через указатель
}

void calculations(int first, int *p_des) {
    int sum = first + *p_des;
    int razn = first - *p_des;
    int proizv = first * *p_des;
    float delenie = (float)first / *p_des;

    printf("\nСумма чисел равна %d ", sum);
    printf("\nРазность чисел равна %d ", razn);
    printf("\nПроизведение чисел равно %d ", proizv);
    printf("\nЧастное чисел равно %.2f", delenie);
}

int main() {
    int first, des;
    char second[50];

    printf("Введите 1-й операнд (число в 16-й сис-ме счисления): ");
    scanf("%x", &first);

    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%s", second);

    dvoichn_in_des(second, &des);
    calculations(first, &des);

    return 0;
}