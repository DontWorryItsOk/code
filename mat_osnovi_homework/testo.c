#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    char hexInteger[20], hexFraction[20];
    double floatValue;

    printf("Введите целую часть шестнадцатеричного вещественного числа: ");
    scanf("%s", hexInteger);

    printf("Введите дробную часть шестнадцатеричного вещественного числа: ");
    scanf("%s", hexFraction);

    // Проверка ввода
    if (!isHexString(hexInteger) || !isHexString(hexFraction)) {
        printf("Ошибка: введены некорректные символы. Пожалуйста, введите шестнадцатеричные цифры.\n");
        return 1; // Возвращаем код ошибки
    }

    // Преобразование строки в вещественное число
    floatValue = hexStringToDouble(hexInteger, hexFraction);

    // Вывод результата
    printf("Введенное вещественное число: %f\n", floatValue);

    return 0;
}
