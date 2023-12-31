#include <stdio.h>
#include <stdlib.h>
typedef int INFO;

struct NODE {
    INFO info;
    struct NODE *next;
};

struct NODE *top = NULL; // указатель на вершину стека

void push(INFO value) {
    struct NODE *tmp = (struct NODE *)malloc(sizeof(struct NODE));
    tmp -> info = value;
    tmp -> next = top;
    top = tmp;
}

INFO pop(void) {
    struct NODE *tmp;
    tmp = top;
    INFO val = tmp -> info;
    top = tmp -> next;
    free(tmp);
    return val;
}

void show(void) {
    struct NODE *tmp = top;
    printf("\nСодержимое стека: \n");
    
    if(tmp == NULL) {
        printf("Стек пуст\n");
        return;
    }

    while(tmp) {
        printf("%d-> ", tmp -> info);
        tmp = tmp -> next;
    }
}

int main() {
    INFO val;
    show();
    do {
        printf("Введите элемент, 0 - конец\n");
        scanf("%d", &val);
        if(!val) break;
        push(val);
    }
    while(1);
    show();
    val = pop();
    printf("<-%d ", val);
    show();
    return 0;
}