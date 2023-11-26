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
    
    else {
        while (des > 0) {
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
    printf(".");
    for (int i = 0; i < 16; i++) { // до 16 знаков после запятой
        decimal *= 2;
        printf("%d", (int)decimal);
        decimal -= (int)decimal;
    }
    }
}

int dvoichn_in_des(char second[50]) {
    int length = strlen(second);
    int des = 0, i = 0;
    for (i = 0; i < length; i++) {
        if (second[i] == '1') {
            des += 1 * pow(2, length - i - 1);
        }
    }
    return des;
}

void calculations(int first, int des) {
    int sum, razn, proizv;
    float delenie;
    sum = first + des;
    razn = first - des;
    proizv = first * des;
    printf("proizv = %d", proizv); // это потом убрать

    if (des == 0)
        delenie = 0;
    else
        delenie = (float)first / des;

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
    } 
    
    else {
        printf("\nЧастное чисел: Ошибка! На 0 делить нельзя!");
    }
}

int main() {
    int first;
    char second[50];

    printf("Введите 1-й операнд (число в 16-й сис-ме счисления): ");
    scanf("%x", &first);

    if (first > 65535) {
        printf("Вы ввели неправильное/слишком большое число");
        exit(1);
    }

    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%s", second);

    int length = strlen(second);
    for (int i = 0; i < length; i++) {
        if (second[i] != '0' && second[i] != '1') {
            printf("\nВы ввели число не в двоичной системе счисления");
            exit(1);
        }
    }

    int des = dvoichn_in_des(second);
    calculations(first, des);

    return 0;
}
// посмотреть что будет если вычесть из меньшего большее