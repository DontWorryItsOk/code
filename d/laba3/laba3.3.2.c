/* Дана квадратная матрица размерности N. Зеркально отразить элементы
относительно побочной диагонали. Вывести исходную и преобразованную
матрицу.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

int arr[5][5],i,j;
srand(time(NULL));

for (i=0;i<5;i++) {
    for(j=0;j<5;j++) {
        arr[i][j] = rand()%100;
    }
}

for (i=0;i<5;i++) {
    for(j=0;j<5;j++) {
    printf("%4d",arr[i][j]);
    } 
    printf("\n");
}

for (i = 4; i >= 0; i--) {
    for (j = 0; j < 5; j++) {
        if(j < 4 - i) // чтобы не заменялись элементы побочной диагонали
        arr[4-i][4-j] = arr[i][j]; // проблема в строчке!
    }
}

// формула побочной диагонали: j=5-i
printf("Симметричный массив\n"); 

for (i=0;i<5;i++) {
    for(j=0;j<5;j++) {
    printf("%4d",arr[i][j]);
    }
    
    printf("\n");
}

return 0;
}