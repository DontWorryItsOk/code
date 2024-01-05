/* Разработайте и реализуйте программу, 
которая выводит все нечетные числа из диапазона, 
состоящего из двух чисел, которые вводит пользователь. */ 

#include <stdio.h>

int main() {
    int arr[2];
    for(int i = 0; i < 2; i++) {
        printf("Введите число номер %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Ваш диапазон чисел: ");
    for(int i = 0; i < 2; i++) {
        printf("%d ", arr[i]);
    }

    int test = 0;
    printf("\nНечетные числа: ");
    for(int i = 0; i < 2; i++) {
        if(arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
            test = 1;
        }
    }

    if(test == 0) printf("отсутствуют");
    return 0;
}