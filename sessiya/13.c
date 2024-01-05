/*Разработайте и реализуйте программу, 
которая находит число с самой большой суммой цифр в массиве чисел, 
введенных пользователем.*/

#include <stdio.h>

int main() {
    int arr[1000], N;
    printf("Введите размер массива: ");
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        printf("Введите %d-й эл-т массива: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Массив: ");
    for(int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    int number, max_number = 0, position, chislo;
    for(int i = 0; i < N; i++) {
        number = 0;
        
        int tmp = arr[i];
        while(arr[i] != 0) {
            number += arr[i]%10;
            arr[i] /= 10;
        }
        
        if(number > max_number) {
            max_number = number;
            position = i + 1;
            chislo = tmp;
        }

    }

    printf("\nЭлемент с самой большой суммой цифр: [%d] %d\nСумма цифр в нем равна: %d", position, chislo, max_number);
    return 0;
}