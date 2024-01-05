/* 21.	Разработайте и реализуйте программу, 
находящую минимальное и максимальное значение на главной и побочной диагоналях квадратной матрицы, 
размерность и содержимое которой задает пользователь.*/

#include <stdio.h>

int main() {
    int arr[100][100], N;
    printf("Введите размер квадратной матрицы: ");
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("Введите [%d][%d] элемент: ", i+1, j+1);
            scanf("%d", &arr[i][j]); // нужно &
        }
    }

    printf("Матрица:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    int i = 0, j = 0, max_g = arr[i][j], min_g = arr[i][j];;
    while(i < N && j < N) {
        if(arr[i][j] > max_g) {
            max_g = arr[i][j];
        }

        if(arr[i][j] < min_g) {
            min_g = arr[i][j];
        }
        i++;
        j++;
    }

    printf("Максимальный элемент главной диагонали: %d, минимальный: %d", max_g, min_g);

    i = 0, j = N-1;
    int max_p = arr[i][j], min_p = arr[i][j];;
    while(i < N && j >= 0) {
        if(arr[i][j] > max_p) {
            max_p = arr[i][j];
        }

        if(arr[i][j] < min_p) {
            min_p = arr[i][j];
        }
        i++;
        j--;
    }

    printf("\nМаксимальный элемент побочной диагонали: %d, минимальный: %d", max_p, min_p);
    return 0;
}