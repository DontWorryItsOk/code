/*3. Дана квадратная матрица размерности N. Найти максимальный элемент элемент
выше побочной диагонали. Вывести саму матрицу в исходном виде, часть
матрицы выше побочной диагонали в треугольном виде и максимальный
элемент*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() 

{

int mas[100][100],i,j;
srand(time(NULL));

int N; // N - размер массива
printf("Введите размер квадратной матрицы: ");
scanf("%d", &N);

printf("Исходная матрица: \n");

for (i = 0;i < N; i++) {
    for(j = 0; j < N; j++) {
        mas[i][j] = rand()%100;
    }
}

for (i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
    printf("%4d", mas[i][j]);
    }
    
    printf("\n");
}