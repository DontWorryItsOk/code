#include <stdio.h>
#include <stdlib.h>
#include <string.h> // для strcpy

struct Price {
    char Tovar[50];
    char Mag[50];
    int Stoim;
    struct Price *next; // указатель на следующий элемент списка
};

struct Price *head = NULL;
struct Price *tail = NULL;
typedef struct Price PRICE;


void add_to_start(PRICE one) {
    PRICE *tmp = (PRICE *)malloc(sizeof(PRICE));
    strcpy(tmp -> Tovar, one.Tovar);
    strcpy(tmp ->Mag, one.Mag);
    tmp ->Stoim = one.Stoim;
    tmp->next = head;
    head = tmp;
    
    if (tail == NULL) {
        tail = tmp;
    }
}


void add_anywhere(PRICE one, PRICE *afterNode) {

}


void add_to_end(PRICE one) {

}


int main() {
    PRICE newtovar;
    printf("Введите название товара: ");
    scanf("%s", newtovar.Tovar);
    printf("Введите название магазина: ");
    scanf("%s", newtovar.Mag);
    printf("Введите стоимость товара в руб.");
    scanf("%d", &newtovar.Stoim);

}