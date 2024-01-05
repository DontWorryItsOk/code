/*Разработайте и реализуйте программу, 
которая подсчитывает количество элементов больше среднего в массиве, 
введенном пользователем.*/

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

    float average = 0, sum = 0;
    for(int i = 0; i < N; i++) {
        sum += arr[i];
    }
    average = sum / N;

    int number = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] > average) number++;
    }
    printf("\nКол-во элементов больше среднего в массиве: %d", number);
    return 0;
}