#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int N;
    int arr[50];
    printf("Введите размер массива: ");
    scanf("%d", &N);

    srand(time(NULL));

    for(int i = 0; i < N; i++) {
        arr[i] = rand()%100;
    }

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(arr[i] == arr[j]) {
                printf("Ошибка! В массиве встретились повторяющиеся значения.");
                exit(1);
            }
        }
    }

    printf("Массив: ");
    for(int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    int razn = arr[1] - arr[0];
    int progression = 1;

    for(int i = 0; i < N-1; i++) {
        if(arr[i+1] - arr[i] != razn) {
            progression = 0;
            break;
        }
    }

    if(progression == 1) {
        printf("\nМассив является арифметической прогрессией. Разность прогрессии: %d", razn);
    }

    else
    return 0;
}