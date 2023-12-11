#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Перевод из десятичной в двоичную
void des_to_dvoichn(int des) {
    int arr[50];
    int i = 0;

    if (des == 0) {
        printf("0");
    }

    if (des < 0) {
        printf("-");
        des = fabs(des);
    }

    while (des != 0) {
        arr[i] = des % 2;
        des = des / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", arr[j]);
    }
}

// Перевод дробной части десятичного числа в двоичную сис-му счисления
void decimal_in_dvoichn(float decimal) {
    if (decimal == 0) {
        // ничего не делаем
    } else {
        decimal = fabs(decimal);
        printf(".");
        for (int i = 0; i < 16; i++) { // до 16 знаков после запятой
            decimal *= 2;
            printf("%d", (int)decimal);
            decimal -= (int)decimal;
            if (decimal == 0) {
                break;
            }
        }
    }
}

// Перевод двоичного числа в десятичную сис-му счисления
float dvoichn_in_des(char binary[50]) {
    int length = strlen(binary); // длина массива
    float result_dvoichn = 0; // общий результат перевода
    int intPart = 0; // целая часть числа
    float decimalPart = 0.0; // дробная часть числа
    int hasDecimal = 0; // переменная для проверки наличия дробной части
    int stepen = -1; // степень для цифр после запятой

    // Проверяем, есть ли дробная часть
    for (int i = 0; i < length; i++) {
        if (binary[i] == '.') {
            hasDecimal = 1; 
            break;
        }
    }

    // Обработка целой части числа
    // Если дробная часть есть
    if (hasDecimal  == 1) {
        int int_length = 0; // длина целой части массива

        for (int i = 0; i < length; i++) {
            if (binary[i] == '.') {
                int_length = i;
                break;
            }
        }

        int i = 0;
        while(binary[i] != '.' ) {
            if (binary[i] == '1') {
                intPart += 1 * pow(2, int_length-1-i);
            }
            i++;
        }
        
        if(binary[0] == '-') { // если число отрицательное, меняем знак
            intPart = -intPart;
        }
    }

    // Если дробной части нет
    if(hasDecimal == 0) {
        for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            intPart += 1 * pow(2, length - i - 1);
        }
    }
        if(binary[0] == '-') { // если число отрицательные
            intPart = -intPart;
        }
    }

    printf("\nintPart_dvoichn = %d", intPart); // это потом убрать

    // Обработка дробной части
    if (hasDecimal == 1) {
        int decimalStart = 0;

        for (int i = 0; i < length; i++) {
            if (binary[i] == '.') {
                decimalStart = i + 1;
                break;
            }
        }

        printf("\nДробная часть: "); // это потом убрать
        for (int i = decimalStart; i < length; i++) {
            if (binary[i] == '1' && binary[0] != '-') {
                decimalPart += 1 * pow(2, stepen);
                printf("\ndecimalPart_dvoichn = %f", decimalPart); // это потом убрать
            }
            // Если число отрицательное:
            if (binary[i] == '1' && binary[0] == '-') { 
                decimalPart -= 1 * pow(2, stepen);
                printf("\ndecimalPart1_dvoichn = %f", decimalPart); // это потом убрать
            }
            stepen--;
        }
    }
    printf("\ndecimalPart_dvoichn = %f", decimalPart); // это потом убрать
    
    // Сложение целой и дробной части и получение результатов
    result_dvoichn = intPart + decimalPart;
    printf("\nresult_dvoichn = %f", result_dvoichn); // это потом убрать
    return result_dvoichn;
}

// Перевод шестнадцатеричного числа в десятичное
float schestn_in_des(char schestn[50]) {
    int length = strlen(schestn);
    printf("\nlength_schestn = %d", length); // это потом убрать
    float result_schestn = 0;  // те же переменные, что и в ф-ции dvoichn_in_des
    int intPart = 0;
    float decimalPart = 0.0;
    int hasDecimal = 0; 
    int stepen = -1; // степень для чисел после запятой

    // Проверяем, есть ли дробная часть
    for (int i = 0; i < length; i++) {
        if (schestn[i] == '.') {
            hasDecimal = 1;
            break;
        }
    }

    // Обработка целой части
    // Если есть дробная часть:
    if (hasDecimal  == 1) {
        int int_length = 0;

        for (int i = 0; i < length; i++) {
            if (schestn[i] == '.') {
                int_length = i;
                break;
            }
        }

        int i = 0;
        while(schestn[i] != '.') {
                switch(schestn[i]) {
        case '0': intPart += 0 * pow(16, int_length - i - 1);
        break;
        case '1': intPart += 1 * pow(16, int_length - i - 1);
        break;
        case '2': intPart += 2 * pow(16, int_length - i - 1);
        break;
        case '3': intPart += 3 * pow(16, int_length - i - 1);
        break;
        case '4': intPart += 4 * pow(16, int_length - i - 1);
        break;
        case '5': intPart += 5 * pow(16, int_length - i - 1);
        break;
        case '6': intPart += 6 * pow(16, int_length - i - 1);
        break;
        case '7': intPart += 7 * pow(16, int_length - i - 1);
        break;
        case '8': intPart += 8 * pow(16, int_length - i - 1);
        break;
        case '9': intPart += 9 * pow(16, int_length - i - 1);
        break;
        case 'A': intPart += 10 * pow(16, int_length - i - 1);
        break;
        case 'B': intPart += 11 * pow(16, int_length - i - 1);
        break;
        case 'C': intPart += 12 * pow(16, int_length - i - 1);
        break;
        case 'D': intPart += 13 * pow(16, int_length - i - 1);
        break;
        case 'E': intPart += 14 * pow(16, int_length - i - 1);
        break;
        case 'F': intPart += 15 * pow(16, int_length - i - 1);
        break;
        }
        printf("\nintpart_schestn_1 = %d", intPart); // это потом убрать
            i++;
        }
        printf("\nintPart_schestn = %d", intPart); // это потом убрать
        
        if(schestn[0] == '-') { // если число отрицательные
            intPart = -intPart;
        }
    }

    // Если дробной части нет:
    if(hasDecimal == 0) {
        for (int i = 0; i < length; i++) {

        switch(schestn[i]) {
        case '0': intPart += 0 * pow(16, length - i - 1);
        break;
        case '1': intPart += 1 * pow(16, length - i - 1);
        break;
        case '2': intPart += 2 * pow(16, length - i - 1);
        break;
        case '3': intPart += 3 * pow(16, length - i - 1);
        break;
        case '4': intPart += 4 * pow(16, length - i - 1);
        break;
        case '5': intPart += 5 * pow(16, length - i - 1);
        break;
        case '6': intPart += 6 * pow(16, length - i - 1);
        break;
        case '7': intPart += 7 * pow(16, length - i - 1);
        break;
        case '8': intPart += 8 * pow(16, length - i - 1);
        break;
        case '9': intPart += 9 * pow(16, length - i - 1);
        break;
        case 'A': intPart += 10 * pow(16, length - i - 1);
        break;
        case 'B': intPart += 11 * pow(16, length - i - 1);
        break;
        case 'C': intPart += 12 * pow(16, length - i - 1);
        break;
        case 'D': intPart += 13 * pow(16, length - i - 1);
        break;
        case 'E': intPart += 14 * pow(16, length - i - 1);
        break;
        case 'F': intPart += 15 * pow(16, length - i - 1);
        break;
        }
    
        printf("\nintpart_schestn_2 = %d", intPart); // это потом убрать
        }

        if(schestn[0] == '-') { // если число отрицательное, меняем знак
            intPart = -intPart;
        }
    }

    printf("\nintPart_schestn = %d", intPart); // это потом убрать

    // Обработка дробной части
    if (hasDecimal == 1) {
        int decimalStart = 0;

        for (int i = 0; i < length; i++) {
            if (schestn[i] == '.') {
                decimalStart = i + 1;
                break;
            }
        }

        printf("\nДробная часть: "); // это потом убрать
        for (int i = decimalStart; i < length; i++) {
                switch(schestn[i]) {
        case '0': decimalPart += 0 * pow(16, stepen);
        break;
        case '1': decimalPart += 1 * pow(16, stepen);
        break;
        case '2': decimalPart += 2 * pow(16, stepen);
        break;
        case '3': decimalPart += 3 * pow(16, stepen);
        break;
        case '4': decimalPart += 4 * pow(16, stepen);
        break;
        case '5': decimalPart += 5 * pow(16, stepen);
        break;
        case '6': decimalPart += 6 * pow(16, stepen);
        break;
        case '7': decimalPart += 7 * pow(16, stepen);
        break;
        case '8': decimalPart += 8 * pow(16, stepen);
        break;
        case '9': decimalPart += 9 * pow(16, stepen);
        break;
        case 'A': decimalPart += 10 * pow(16, stepen);
        break;
        case 'B': decimalPart += 11 * pow(16, stepen);
        break;
        case 'C': decimalPart += 12 * pow(16, stepen);
        break;
        case 'D': decimalPart += 13 * pow(16, stepen);
        break;
        case 'E': decimalPart += 14 * pow(16, stepen);
        break;
        case 'F': decimalPart += 15 * pow(16, stepen);
        break;
        }
        }
                stepen--;
                printf("\ndecimalPart_schestn1 = %f", decimalPart); // это потом убрать
            }

            if (schestn[0] == '-') {
                decimalPart = -decimalPart;
                printf("\ndecimalPart1_schestn2 = %f", decimalPart); // это потом убрать
            }
            
    printf("\ndecimalPart_schestn = %f", decimalPart); // это потом убрать
    
    // Сложение целой и дробной части
    result_schestn = intPart + decimalPart;
    printf("\nresult_schestn = %f", result_schestn); // это потом убрать
    return result_schestn;
}

// Функция с вычислениями и последуюющим переводом чисел в двоичную систему счисления
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
    char first[50];
    char second[50];

    printf("Введите 1-й операнд (число в 16-й сис-ме счисления): ");
    scanf("%s", first);
    
    if (strspn(first, "0123456789ABCDEF.-") != strlen(first)) { // проверка вводимых значений
            printf("Вы ввели число не в шестнадцатеричной сис-ме счисления");
            exit(1);
    }

    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%s", second);

    int length = strlen(second);
    for (int i = 0; i < length; i++) { // проверка вводимых значений
        if (second[i] != '0' && second[i] != '1' && second[0] != '-' && second[i] != '.') {
            printf("\nВы ввели число не в двоичной системе счисления");
            exit(1);
        }
    }

    float dv_des = dvoichn_in_des(second);
    float sch_des = schestn_in_des(first);
    calculations(sch_des, dv_des);
 
    return 0;
}
/* 
 добавить проверку для 16-х чисел

варианты для проверки:
A101 0 /
0 110110 /
A4F1 11001100 /
B3C9 110110.1101110 /
B3C9.424 110110.11011101 /
-B36 11011 /
-B36.4 11011.11 /
-B36.4 -11011.11 /

A4BL 110110 /
A4.L 110110 /
C1 110102
C1 11011.11010210

*/