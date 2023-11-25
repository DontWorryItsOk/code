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

void des_to_dvoichn(int des) {
    int arr[50];
    int i = 0;

    while (des > 0) {
        arr[i] = des % 2;
        des = des / 2;
        i++;
    }

    for(int j = i - 1; j >=0; j--) {
        printf("%d", arr[j]);
    }
}

int dvoichn_in_des(char second[50]) {
    int length = strlen(second);
    int des = 0, i = 0;
    for (i = 0; i < length + 1; i++) {
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

    printf("\nСумма чисел равна ");
    des_to_dvoichn(sum);
    printf("\nРазность чисел равна ");
    des_to_dvoichn(razn);
    printf("\nПроизведение чисел равно ");
    des_to_dvoichn(proizv);
    printf("\nЧастное чисел равно ");
    des_to_dvoichn(delenie);
}

int main() {
    int first;
    char second[50];

    printf("Введите 1-й операнд (число в 16-й сис-ме счисления): ");
    scanf("%x", &first); // %x - ввод числа в 16-й сис-ме счисления
    
    if(first > 65535) { // проверка вводимых значений - ограничение в 65535 - для 16-битовых чисел
        printf("Вы ввели неправильное/слишком большое число");
        exit(1);
    }

    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%s", second);

    int length = strlen(second); // длина полученного масива
    for(int i = 0; i < length; i++) { // проверка вводимых значений
        if(second[i] != '0' && second[i] != '1') {
            printf("\nВы ввели число не в двоичной системе счисления");
            exit(1);
        }
    }

    int des = dvoichn_in_des(second);
    calculations(first, des);

    return 0;
}
// A1 и 1010 провереноL