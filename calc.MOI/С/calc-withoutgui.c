#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Функция для преобразования шестнадцатеричной строки в десятичное число
int hexToDec(char hex[]) {
    int decimal = 0;
    int length = strlen(hex);

    for (int i = 0; i < length; ++i) {
        int digit;

        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else {
            printf("Ошибка: неверный символ в шестнадцатеричной строке\n");
            exit(EXIT_FAILURE);
        }

        decimal = decimal * 16 + digit;
    }

    return decimal;
}

// Функция для преобразования восьмеричной строки в десятичное число
int octToDec(char oct[]) {
    int decimal = 0;
    int length = strlen(oct);

    for (int i = 0; i < length; ++i) {
        int digit;

        if (oct[i] >= '0' && oct[i] <= '7') {
            digit = oct[i] - '0';
        } else {
            printf("Ошибка: неверный символ в восьмеричной строке\n");
            exit(EXIT_FAILURE);
        }

        decimal = decimal * 8 + digit;
    }

    return decimal;
}

// Функция для преобразования десятичного числа в шестнадцатеричную строку
void decToHex(int dec, char hex[]) {
    int remainder, i = 0;
    char hexDigits[] = "0123456789ABCDEF";

    // Обрабатываем случай, когда число равно 0
    if (dec == 0) {
        hex[0] = '0';
        hex[1] = '\0';
        return;
    }

    // Переводим десятичное число в шестнадцатеричное
    while (dec > 0) {
        remainder = dec % 16;

        // Преобразуем остаток в символ
        hex[i++] = hexDigits[remainder];

        dec = dec / 16;
    }

    // Добавляем завершающий ноль
    hex[i] = '\0';

    // Инвертируем строку
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = hex[start];
        hex[start] = hex[end];
        hex[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char hexOperand1[20], octOperand2[20], operator;
    int decOperand1, decOperand2, result;

    // Ввод первого операнда в шестнадцатеричной системе
    printf("Введите первый операнд (в шестнадцатеричной системе): ");
    scanf("%s", hexOperand1);
    decOperand1 = hexToDec(hexOperand1);

    // Ввод второго операнда в восьмеричной системе
    printf("Введите второй операнд (в восьмеричной системе): ");
    scanf("%s", octOperand2);
    decOperand2 = octToDec(octOperand2);

    // Ввод оператора
    printf("Введите оператор (+, -, *, /): ");
    scanf(" %c", &operator);

    // Вычисление результата в десятичной системе
    switch (operator) {
        case '+':
            result = decOperand1 + decOperand2;
            break;
        case '-':
            result = decOperand1 - decOperand2;
            break;
        case '*':
            result = decOperand1 * decOperand2;
            break;
        case '/':
            if (decOperand2 == 0) {
                printf("Ошибка: деление на ноль\n");
                exit(EXIT_FAILURE);
            }
            result = decOperand1 / decOperand2;
            break;
        default:
            printf("Ошибка: неверный оператор\n");
            exit(EXIT_FAILURE);
    }

    // Вывод результата в шестнадцатеричной системе
    char hexResult[20];
    decToHex(result, hexResult);
    printf("Результат: %s\n", hexResult);

    return 0;
}
