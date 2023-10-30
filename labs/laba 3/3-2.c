/*Дан целочисленный массив размера N. Поменять порядок элементов на
обратный.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mas[10000];
    int i, N, tmp1 ;
    srand(time(NULL));
    
    printf("Введите размер массива:");
    scanf("%d",&N);

for (i=0; i<N; i++) 
    {
    mas[i] = rand()%1000;
    printf("%d ", mas[i]);   //Задали тут массив
    }
    printf("\n");
    printf("Result: \n");
for (i=0; i<(N-1)/2; i++) // ограничили цикл до середины
    {
    tmp1=mas[i];
    mas[i]= mas[N-i-1]; 
    mas[N-i-1]= tmp1;
    printf("%d ", mas[i]);
    }
for(i=(N-1)/2; i<N; i++) // продолжаем с середины
    {
        printf("%d ", mas[i]);
    }

return 0;
}