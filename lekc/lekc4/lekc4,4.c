#include <stdio.h>
int main() {
    int mas [3] [4]; // двухмерный массив с 3 строками и 4 столбцами
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("Введите [%d][%d] эл-т: ", i, j);
            scanf("%d", &mas[i][j]);
        }
    }
printf("\n");
for(i = 0; i < 3; i++) {
    for(j = 0; j < 4; j++) {
        printf("%4d", mas [i] [j]);
    }
    printf("\n");
}
}
