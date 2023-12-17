#include <stdio.h>
#include <stdlib.h>
#include <string.h> // для strcpy

struct Price {
    char Tovar[50];
    char Mag[50];
    int Stoim;
    struct Price *next; // указатель на следующий элемент списка
};

struct Price *head = NULL; // указатель на вершину
struct Price *tail = NULL; // указатель на конец
typedef struct Price PRICE;


void add_to_start(PRICE one) {
    PRICE *tmp = (PRICE *)malloc(sizeof(PRICE));
    strcpy(tmp -> Tovar, one.Tovar);
    strcpy(tmp ->Mag, one.Mag);
    tmp ->Stoim = one.Stoim; // tmp - переменная для.............
    tmp->next = head;
    head = tmp;
    
    if (tail == NULL) {
        tail = tmp;
    }
}


void add_to_end(PRICE one) {
    PRICE *tmp = (PRICE *)malloc(sizeof(PRICE));
    strcpy(tmp -> Tovar, one.Tovar);
    strcpy(tmp ->Mag, one.Mag);
    tmp ->Stoim = one.Stoim;
    tmp->next = head;

    if (head == NULL) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
}


void add_anywhere(PRICE one, PRICE *after) {
    if(after == NULL) {
        printf("Ошибка: Указанный узел для вставки отсутствует.\n");
        return;
    }
    PRICE *tmp = (PRICE *)malloc(sizeof(PRICE));
    strcpy(tmp -> Tovar, one.Tovar);
    strcpy(tmp ->Mag, one.Mag);
    tmp ->Stoim = one.Stoim;
    tmp->next = head;
    after -> next = tmp;

    // Если after - последний элемент, обновим tail(конец)
    if (after == tail) {
        tail = tmp;
    }
}


void delete_from_start() {

}


void delete__from_end() {

}


void delete_anywhere() {

}


void show() {

}

void free_memory() {

}


int main() {
    int value;
    do {
        printf("Введите элемент, 0 - конец\n");
        scanf("%d", &value);
        if (!value) break;
        
        PRICE newtovar;
        printf("Введите название товара: ");
        scanf("%s", newtovar.Tovar);
        printf("Введите название магазина: ");
        scanf("%s", newtovar.Mag);
        printf("Введите стоимость товара в руб.");
        scanf("%d", &newtovar.Stoim);
        } while (1);

    printf("\nСписок товаров:\n");
    show();

    return 0;
}