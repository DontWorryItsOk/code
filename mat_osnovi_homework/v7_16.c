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
        printf(".");
        for (int i = 0; i < 16; i++) { // до 16 знаков после запятой
            decimal *= 2;
            printf("%d", (int)decimal);
            decimal -= (int)decimal;
            if(decimal == 0) {
                break;
            }
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
        if (binary[i] == '.') {
            hasDecimal = 1;
            break;
        }
    }

    // Обработка целой части
    if (hasDecimal  == 1) {
        int int_length = 0;

        for (int i = 0; i < length; i++) {
            if (binary[i] == '.') {
                int_length = i;
                break;
            }
        }

        int i = 0;
        while(binary[i] != '.' ) {
            if (binary[i] == '1') {
                integerPart += 1 * pow(2, int_length-1-i);
            }
            i++;
        }
    }

    if(hasDecimal == 0) {
        for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            integerPart += 1 * pow(2, length - i - 1);
        }
    }
    }
    printf("\nintegerpart = %d", integerPart); // это потом убрать

    // Обработка дробной части
    if (hasDecimal == 1) {
        int decimalStartIndex = 0;

        for (int i = 0; i < length; i++) {
            if (binary[i] == '.') {
                decimalStartIndex = i + 1;
                break;
            }
        }

        printf("\nДробная часть: "); // это потом убрать
        for (int i = decimalStartIndex; i < length; i++) {
            if (binary[i] == '1') {
                decimalPart += 1 * pow(2, stepen);
                printf("\ndecimalPart1 = %f", decimalPart); // это потом убрать
            }
            stepen--;
        }
    }
    printf("\ndecimalPart = %f", decimalPart); // это потом убрать
    // Сложим целую и дробную части
    result = integerPart + decimalPart;
    printf("\nresult = %f", result); // это потом убрать
    return result;
}


double hexStringToDouble(const char *hexInteger, const char *hexFraction) {
    char fullHexString[40]; // предположим, что максимальная длина строки не превышает 40 символов
    snprintf(fullHexString, sizeof(fullHexString), "0x%s.%sp0", hexInteger, hexFraction);

    char *endptr;
    return strtod(fullHexString, &endptr);
}


int isHexString(const char *str) {
    // Проверка, что строка состоит только из шестнадцатеричных символов
    return strspn(str, "0123456789ABCDEFabcdef") == strlen(str);
}


void calculations(float first, float des) {
    float sum, razn, proizv, delenie;
    sum = first + des;
    printf("\nперед вычислениями: first = %f second = %f", first, des); // это потом убрать
    printf("\nsum = %f", sum); // это потом убрать
    razn = first - des;
    printf("\nrazn = %f", razn); // это потом убрать
    proizv = first * des;
    printf("\nproizv = %f", proizv); // это потом убрать

    if (des == 0)
        delenie = 0;
    
    else {
        delenie = (float)first / des;
        printf("\ndelenie = %f", delenie); // это потом убрать
    }

    printf("\nСумма чисел: ");
    des_to_dvoichn((int)sum);
    decimal_in_dvoichn((float)sum - (int)sum); // !!!!!!!!!!!!
    printf("\nРазность чисел: ");
    des_to_dvoichn((int)razn);
    decimal_in_dvoichn((float)razn - (int)razn); // !!!!!!!!!!!!!
    printf("\nПроизведение чисел: ");
    des_to_dvoichn((int)proizv);
    decimal_in_dvoichn((float)proizv - (int)proizv); // !!!!!!!!!!!!

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
    
    char hexInteger[20], hexFraction[20];
    double floatValue;

    printf("Введите 1-й операнд (целую часть шестнадцатеричного числа): ");
    scanf("%s", hexInteger);

    printf("Введите 1-й операнд (дробную часть шестнадцатеричного числа): ");
    scanf("%s", hexFraction);

    // Проверка ввода
    if (!isHexString(hexInteger) || !isHexString(hexFraction)) {
        printf("Ошибка: введены некорректные символы.\n");
        return 1; // Возвращаем код ошибки
    }
    
    // Преобразование строки в вещественное число
    floatValue = hexStringToDouble(hexInteger, hexFraction);


    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%s", second);

    int length = strlen(second);
    for (int i = 0; i < length; i++) { // проверка вводимых значений
        if (second[i] != '0' && second[i] != '1' && second[0] != '-' && second[i] != '.') {
            printf("\nВы ввели число не в двоичной системе счисления");
            exit(1);
        }
    }

    float des = dvoichn_in_des(second);
    calculations(first, des);
 
    return 0;
}
/* 
16-е вещественное число?


варианты для проверки:
A101 0
0 110110
A4F1 11001100
B3C9 110110.1101110
B3C9 110110.11011101

*/