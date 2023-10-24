#include <stdio.h>
int main() {
    int OX, OY;
    printf("Введите координату OX: ");
    scanf("%d", &OX);
    printf("Введите координату OY: ");
    scanf("%d", &OY);
    
    if (OX > 0 && OY > 0) {
        printf("Точка находится в 1 четверти\n");
    }
    
    if (OX > 0 && OY < 0) {
        printf("Точка находится в 4 четверти\n");
    }
    
    if (OX < 0 && OY < 0) {
        printf("Точка находится в 3 четверти\n");
    }
   
   if (OX < 0 && OY > 0) {
        printf("Точка находится во 2 четверти\n");
    }

    return 0;
}
