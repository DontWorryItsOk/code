/* Разработайте и реализуйте функцию, которая принимает 2 численные переменные и меняет их значения местами.*/
#include <stdio.h>

void func(int a, int b) {
    int tmp;
    tmp = b;
    b = a;
    a = tmp;
    printf("a = %d, b = %d", a, b);
}


int main() {
    int a, b;
    printf("Введите переменные a и b: ");
    scanf("%d %d", &a, &b);
    func(a, b);
    return 0;
}