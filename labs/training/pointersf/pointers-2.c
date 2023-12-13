#include <stdio.h>

int main(){
    char c = 'N';
    int d = 10;
    short s = 2;

    char *pc = &c;
    int *pd = &d;
    short *ps = &s;

    printf("Variable c: address=%p \t value=%c \n",  pc, *pc);
    printf("Variable d: address=%p \t value=%d \n",  pd, *pd);
    printf("Variable s: address=%p \t value=%hd \n", ps, *ps);
}