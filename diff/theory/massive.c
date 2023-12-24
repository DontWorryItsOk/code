// Удаление первого элемента массива
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[100], N;
    printf("Введите размер массива: ");
    scanf("%d", &N);

    srand(time(NULL));
    
    printf("Массив:\n");
    for(int i = 0; i < N; i++) {
        arr[i] = rand()%100;
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        arr[i] = arr[i + 1];
    }
    N--; //

    printf("\nНовый массив:\n");
    for(int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}
