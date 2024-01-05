/* 19.	Разработайте и реализуйте программу, 
которая проверяет является ли возрастающей последовательностью массив, 
введенный пользователем.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    int k = 0, test = 1;
    int razn = arr[k+1] - arr[k];
    for(int i = 0; i < N - 1; i++) {
        if(arr[i+1] - arr[i] != razn || arr[i] >= arr[i+1]) {
            test = 0;
        }
    }
    
    if(test == 1 && N > 1) {
        printf("\nМассив является возрастающей последовательностью");
    }
    else {
        printf("\nМассив не является возрастающей последовательностью");
    }
    return 0;
}