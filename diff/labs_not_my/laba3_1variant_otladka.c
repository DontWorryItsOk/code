#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    for(int i = 0; i < 8; i++) {
        for(int j = i+1; j < 8; j++) {
            if(arr[i] == arr[j]) {
                printf("Ошибка! В массиве встретились повторяющиеся значения.");
                exit(1);
            }
        }
    }

    printf("Массив: ");
    for(int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }

    int razn = arr[1] - arr[0];
    int progression = 1;

    for(int i = 0; i < 7; i++) {
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