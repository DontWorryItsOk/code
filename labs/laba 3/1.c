/*Дан массив целых чисел размера N. Найти номера тех элементов массива,
которые больше своего правого соседа, а также количество этих элементов.
Найденные номера выводить в порядке возрастания*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int mas[10000];
    int i, N, tmp1;
    srand(time(NULL));
    
    printf("Введите размер массива:");
    scanf("%d",&N);

for (i=0; i<N; i++) 
    {
    mas[i] = rand()%1000;
    printf("%d ", mas[i]);   //Задали тут массив
    }
/*Дан массив целых чисел размера N. Найти номера тех элементов массива,
которые больше своего правого соседа, а также количество этих элементов.
Найденные номера выводить в порядке возрастания*/

for (i=0; i<N-1; i++) // n-1 для того, чтобы не считало последний эл-т
{
 if (mas[i]>mas[i+1]) // сравниваем левый эл-т с правым
    {
    printf("\nБольший эл-т: %d ", i );
    tmp1++;
    }
}
printf("\n--- Кол-во эл-тов: %d ---", tmp1);
}