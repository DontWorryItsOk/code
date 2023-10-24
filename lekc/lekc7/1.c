// массив работающий по принципу стека
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50 

void push(int value);
int pop(void);
int *tos, *p1, stack[SIZE];

int main() {
    int val;
    tos = stack;
    p1 = stack;
    do {
        printf("Введите число: ");
        scanf("%d", &val);
        if(val != 0) {
        push(val);
        }
        else {
        printf("Число на вершине: %d", pop());
        }
    }
        while(val != -1);
        return 0;
    }

void push(int value) {
    p1++;
    if(p1 == (tos+SIZE))
    printf("Стек переполнен");
    exit(1);
}

int pop(void) {
    if(p1 == tos) {
        printf("Стек идет");
        exit(2);
    }
    p1--;
    return *(p1+1);
}