/* Дана квадратная матрица размерности N. Зеркально отразить элементы
относительно побочной диагонали. Вывести исходную и преобразованную
матрицу.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

int arr[100][100],i,j;
srand(time(NULL));

int N; // N - размер массива
printf("Введите размер квадратной матрицы: ");
scanf("%d", &N);

printf("Исходная матрица: \n");

for (i = 0;i < N; i++) {
    for(j = 0; j < N; j++) {
        arr[i][j] = rand()%100;
    }
}

for (i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
    printf("%4d", arr[i][j]);
    }
    
    printf("\n");
}

int tmp;
for (i = N-1; i >= 0; i--) {
    for (j = 0; j < N; j++) {
        if(j < N-i-1) { // чтобы не заменялись элементы побочной диагонали
        tmp = arr[N-i-1][N-j-1];
        arr[N-i-1][N-j-1] = arr[i][j];
        arr[i][j] = tmp;
        }
    }
}
// формула побочной диагонали: j=5-i

printf("Симметричная матрица: \n"); 

for (i = 0;i < N; i++) {
    for(j = 0; j < N; j++) {
    printf("%4d", arr[i][j]);
    }
    
    printf("\n");
}

return 0;
}