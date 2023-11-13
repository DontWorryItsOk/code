/* Дан целочисленный массив размера N. Найти максимальный из элементов, не 
являющихся ни локальным минимумом, ни локальным максимумом. Если 
такого элемента нет – вывести 0. Локальный минимум – элемент, который 
меньше любого из своих соседей. Локальный максимум – элемент, который 
больше любого из своих соседей.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    printf("Введите размер массива: ");
    scanf("%d", &N);

    int arr[1000], i;
   srand(time(NULL));
  
   for (i=0; i<N; i++) {
    arr[i] = rand()%(N*10);
    printf("%d ", arr[i]);
   }
   
   int nelocal;
   int max_nelocal = 0;
     
     for (i=1; i<(N-1); i++) {
        if ((arr[i] < arr[i-1] && arr[i] > arr[i+1]) || (arr[i] > arr[i-1] && arr[i] < arr[i+1])) {
          nelocal = arr[i];
        if (nelocal > max_nelocal) {
                max_nelocal = nelocal; // nelocal становится max_nelocal, если он больше предыдущего max_nelocal
            }
        }
    }
    
    printf("\nМаксимальный из элементов, не являющийся локальным минимумом или максимумом = %d", max_nelocal);

    return 0;
}