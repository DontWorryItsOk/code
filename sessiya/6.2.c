/* Разработайте и реализуйте программу, 
находящую минимальное и максимальное значение в строке и столбце квадратной матрицы. 
Размерность, содержимое матрицы и номера строки  и столбца задает пользователь. */

#include <stdio.h>
#include <limits.h>

int main() {
    int arr[100][100], N;
    printf("Введите размер квадратной матрицы: ");
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("Введите [%d][%d] элемент: ", i+1, j+1);
            scanf("%d", &arr[i][j]); // в двумерном массиве нужно &
        }
    }

    printf("Матрица:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    int max_result = INT_MIN, min_result = INT_MAX, number;
    printf("Введите номер строки, в которой нужно найти макс. и мин. значения: ");
    scanf("%d", &number);

    for(int j = 0; j < N; j++) {
        if(arr[number - 1][j] > max_result) max_result = arr[number - 1][j];
        if(arr[number - 1][j] < min_result) min_result = arr[number - 1][j];
    }

    int number_stolb, max_stolb = INT_MIN, min_stolb = INT_MAX, max_result_stolb = INT_MIN, min_result_stolb = INT_MAX;
    printf("Введите номер столбца, в котором нужно найти макс. и мин. значения: ");
    scanf("%d", &number_stolb);

    for(int i = 0; i < N; i++) {
        if(arr[i][number_stolb - 1] > max_stolb) max_stolb = arr[i][number_stolb - 1];
        if(arr[i][number_stolb - 1] < min_stolb) min_stolb = arr[i][number_stolb - 1];
    }

    // Обновленные условия для столбца
    if (max_stolb > max_result_stolb) max_result_stolb = max_stolb;
    if (min_stolb < min_result_stolb) min_result_stolb = min_stolb;

    printf("Максимальное значение в строке %d: %d\nМинимальное значение в строке %d: %d\nМаксимальное значение в столбце %d: %d\nМинимальное значение в столбце %d: %d", number, max_result, number, min_result, number_stolb, max_result_stolb, number_stolb, min_result_stolb);
    return 0;
}