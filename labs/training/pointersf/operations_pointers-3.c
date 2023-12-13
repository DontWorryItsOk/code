#include <stdio.h>
int main(){

    int a = 5;
    int b = 10;

    int *pa = &a;
    int *pb = &b;

    printf("Variable a: address=%p \t value=%d \n", (void*)pa, *pa);
    printf("Variable b: address=%p \t value=%d \n", (void*)pb, *pb);
    pa = pb; // теперь указатель pa хранит адрес переменной b
    printf("Variable b: address=%p \t value=%d \n", (void*)pa, *pa);
}