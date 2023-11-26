#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void des_to_dvoichn(int des) {
    int arr[50];
    int i = 0;

    if (des == 0) {
        printf("0");
    }

    else if (des < 0) {
        des = fabs(des); // берем модуль числа
          while (des != 0) {
            arr[i] = des % 2;
            des = des / 2;
            i++;
        }
        printf("-");
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", arr[j]);
        }
    }
    
    else if(des > 0) {
        while (des != 0) {
            arr[i] = des % 2;
            des = des / 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            printf("%d", arr[j]);
        }
    }
}

void decimal_in_dvoichn(float decimal) {
    
    if(decimal == 0) {
        // ничего не делаем
    }

    else {
        decimal = fabs(decimal);
        printf(",");
        for (int i = 0; i < 16; i++) { // до 16 знаков после запятой
            decimal *= 2;
            printf("%d", (int)decimal);
            decimal -= (int)decimal;
        }
    }
}

float dvoichn_in_des(char binary[50]) {
    int length = strlen(binary);
    float result = 0;
    int integerPart = 0;
    float decimalPart = 0.0;
    int hasDecimal = 0;
    int stepen = -1; // степень для чисел после запятой

    // Проверяем, есть ли дробная часть
    for (int i = 0; i < length; i++) {
        if (binary[i] == ',') {
            hasDecimal = 1;
            break;
        }
    }

    // Обработка целой части
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            integerPart += 1 * pow(2, length - i - 1);
        }
    }

    // Обработка дробной части
    if (hasDecimal == 1) {
        int decimalStartIndex = 0;

        for (int i = 0; i < length; i++) {
            if (binary[i] == ',') {
                decimalStartIndex = i + 1;
                break;
            }
        }

        printf("Дробная часть: "); // это потом убрать
        for (int i = decimalStartIndex; i < length; i++) {
            if (binary[i] == '1') {
                decimalPart += 1 * pow(2, stepen);
                stepen--;
                printf("\ndecimalPart1 = %f", decimalPart); // это потом убрать
            }
        }
    }
    printf("\ndecimalPart2 = %f", decimalPart); // это потом убрать
    // Сложим целую и дробную части
    result = integerPart + decimalPart;
    printf("result = %f", result); // это потом убрать
    return result;
}

void calculations(int first, int des) {
    int sum, razn, proizv;
    float delenie;
    sum = first + des;
    printf("\nsum = %d", sum); // это потом убрать
    razn = first - des;
    printf("\nrazn = %d", razn); // это потом убрать
    proizv = first * des;
    printf("\nproizv = %d", proizv); // это потом убрать

    if (des == 0)
        delenie = 0;
    
    else {
        delenie = (float)first / des;
        printf("\ndelenie = %f", delenie); // это потом убрать
    }

    printf("\nСумма чисел: ");
    des_to_dvoichn(sum);
    printf("\nРазность чисел: ");
    des_to_dvoichn(razn);
    printf("\nПроизведение чисел: ");
    des_to_dvoichn(proizv);

    if (des != 0) {
        printf("\nЧастное чисел: "); 
        des_to_dvoichn((int)delenie);
        decimal_in_dvoichn(delenie - (int)delenie);
        printf("\nostatok del = %f", delenie - (int)delenie); // это потом убрать
    } 

    else { // проверка вводимых значений
        printf("\nЧастное чисел: Ошибка! На 0 делить нельзя!");
    }
}

int main() {
    int first;
    char second[50];

    printf("Введите 1-й операнд (число в 16-й сис-ме счисления): ");
    scanf("%x", &first); // %x - ввод числа в 16-й сис-ме счисления

    if (first > 65535) { // проверка вводимых значений
        printf("Вы ввели неправильное/слишком большое число");
        exit(1);
    }

    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%s", second);

    int length = strlen(second);
    for (int i = 0; i < length; i++) { // проверка вводимых значений
        if (second[i] != '0' && second[i] != '1' && second[0] != '-' && second[i] != ',') {
            printf("\nВы ввели число не в двоичной системе счисления");
            exit(1);
        }
    }

    int des = dvoichn_in_des(second);
    calculations(first, des);
 
    return 0;
}
// все работает и с 0, и с отрицательным 2-м операндом, и когда 2 числа отрицательные
// осталось добавить вычисления с дробными числами