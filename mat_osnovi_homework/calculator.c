/* Написать калькулятор для целых чисел. Операнды и результат
могут быть заданы в разных системах счисления.
Требования:
1. оконный интерфейс;
2. контроль вводимых значений. 

1 операнд - 16
2 операнд - 2 
результат - 2 */

#include <stdio.h>
int i;

int schestn_in_des(char first[50]) {
    for(i = 0; i < 50; i++) {
      
    }
}

int dvoichn_in_des(int second) {

}

int calculations(int first, int second) {

}

int main() {
    char first[50];
    int second;
    
    printf("Введите 1-й операнд (число в 16-й сис-ме счисления): ");
    scanf("%s", first);

    printf("Введите 2-й операнд (число в 2-й сис-ме счисления): ");
    scanf("%d", &second);
    
    schestn_in_des(first);
    return 0;
}