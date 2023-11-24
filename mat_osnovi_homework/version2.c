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
#include <stdlib.h>


int dvoichn_in_des(char second[50]) {
    int length = strlen(second);
    int des = 0, i = 0;
    for (i = 0; i < 50; i++) {
        if (second[i] == '1') {
            des += 1 * pow(2, length - i - 1);
        }
    }
    return des;
}

void calculations(int first, int des) {
    int sum = first + des;
    int razn = first - des;
    int proizv = first * des;
    float delenie = (float)first / des;

    printf("\nСумма чисел равна %d ", sum);
    printf("\nРазность чисел равна %d ", razn);
    printf("\nПроизведение чисел равно %d ", proizv);
    printf("\nЧастное чисел равно %.2f", delenie);
    // добавить перевод в двоичную систему
}

int main() {
    int first;
    char second[50];

    printf("Введите 1-й операнд (число в 16-й сис-ме счисления): ");
    scanf("%x", &first);
    
    if(first > 65535) { // проверка вводимых значений - ограничение в 65535 - для 16-битовых чисел
        printf("Вы ввели неправильное/слишком большое число");
        exit(1);
    }

    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%s", second);

    for(int i = 0; i < (strlen(second)); i++) { // проверка вводимых значений
    printf("%d", strlen(second));
        if(second[i] != '0' && second[i] != '1') {
            printf("Вы ввели число не в двоичной системе счисления");
            exit(1);
        }
    }

    int des = dvoichn_in_des(second);
    calculations(first, des);

    return 0;
}