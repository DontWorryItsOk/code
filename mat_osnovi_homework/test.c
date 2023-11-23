/* Написать калькулятор для целых чисел. Операнды и результат
могут быть заданы в разных системах счисления.
Требования:
1. оконный интерфейс;
2. контроль вводимых значений. 

1 операнд - 16
2 операнд - 2 
результат - 2 */

#include <stdio.h>
#include <string.h> // для ф-ции strlen
#include <math.h>

int i;

void schestn_in_des(int first) { // 16-я система автоматом переводится в десятичную и может выполнять операции с другими числами, функцию можно удалять
    int a = first % 10;
    printf("a = %d", a);
    int b = 3059;
    printf("\nfirst+b = %d", first+b);
}

void dvoichn_in_des(char second[50]) {
    int length = strlen(second);
    int des = 0;
    for(i = 0; i < 50; i++) {
        if(second[i] == '1') {
            des += 1*pow(2,length-i-1);
        }
    }
    printf("\n%d ", des);
    int *p_des = des;
}

void calculations(int first, int des) {
    int sum = first + des;
    int razn = first - des;
    int proizv = first * des;
    float delenie = (float)first / des;
    printf("\nСумма чисел равна %d ", sum);
    printf("\nРазность чисел равна %d ", razn);
    printf("\nПроизведение чисел равно %d ", proizv);
    printf("\nЧастное чисел равно %f", delenie);
}

int main() {
    int first, des;
    char second[50];
    
    printf("Введите 1-й операнд (число в 16-й сис-ме счисления): ");
    scanf("%x", &first); // %x - число в 16-й сис-ме счисления

    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%s", second);
    
    schestn_in_des(first);
    dvoichn_in_des(second);
    calculations(first, &des);

    return 0;
}