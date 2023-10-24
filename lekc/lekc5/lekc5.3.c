#include <stdio.h>
int find_number (int number)
{
    int mas [] = {1, -10, 22, 13, -4, 6, 15};
    int N = 7, i;

    for(i = 0; i < N; i++) {
        if(mas[i] == number)
        return i; // exit(0) завершает выполнения программы
    }
    
    return -1;
}

int main() {
    int x, num;
    printf("Введите иcкомое число: ");
    scanf("%d", &x);

    if(num = find_number(x) == -1) {
        printf("Число не найдено");
    }
    
    else {
        printf("Позиция в массиве: %d", num);
    }
}