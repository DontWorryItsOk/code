/* Дан целочисленный массив размера N. Найти максимальное количество
одинаковых его элементов. */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int i, j, N, arr[10] = {1, 2, 8, 1, 5, 8, 7, 8, 0, 0};

    printf("Массив: ");
    for(i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    int element, max_element = 1; // кол-во одинаковых элементов и макс. кол-во одинаковых элементов

    for (i = 0; i < 10; i++) { // Кол-во сравнений последовательных элементов со всеми остальными
        element = 1; // Обновление переменной в начале каждого этапа цикла
        
        for (j = i+1; j < 10; j++) { // i элемент массива проверяется на равенство с последующими (i+1). Проверять с предыдущими нет смысла, т.к. если одинаковые уже встречались, то они проверились друг с другом
            
            if (arr[i] == arr[j]) {
                element++;
            }
        }

        if(element > max_element) { // Проверяется, больше ли одинаковых элементов здесь, чем в предыдущий раз. Если нет, то переменная не обновляется
            max_element = element; 
        }
    }
    printf("\nМаксимальное кол-во одинаковых эл-в: %d", max_element);
    return 0;
}