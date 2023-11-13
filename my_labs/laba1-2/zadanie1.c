#include <stdio.h>

int main() {
    int ax, bx, cx;
    printf("Введите координату Х точки А: ");
    scanf("%d", &ax);
    printf("Введите координату Х точки C: ");
    scanf("%d", &cx);
    printf("Введите координату Х точки B: ");
    scanf("%d", &bx);
    
    int AC = cx - ax, CB = bx - cx;
    int proizv = AC * CB;
    printf("Произведение длин отрезков AC и CB равно %d",proizv);

    return 0;
}