#include <stdio.h>
void swap (int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap (int x, int y);
int main() {
    int x, y;
    printf("Введите число: ");
    scanf("%d %d", &x, &y);
    printf("x = %d, y = %d\n", x, y);
    swap(x,y);
    printf("x = %d, y = %d\n", x,y);
    
    return 0;
}