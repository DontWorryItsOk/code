#include <stdio.h>
#include <stdlib.h>
#include <string.h> // для strcpy

struct Price {
    char Tovar[50];
    char Mag[50];
    int Stoim;
    struct Price *next;
};

struct Price *head = NULL;
struct Price *tail = NULL;
typedef struct Price PRICE;

void AddToStart(PRICE one) {
    PRICE *tmp;
    tmp = (PRICE *)malloc(sizeof(PRICE));
    tmp ->Tovar = one.Tovar;
    tmp ->Mag = one.Mag;
    tmp ->Stoim = one.Stoim;
    
    if(!tail) head = tmp; //??
    else tail ->next = tmp;
    tail = tmp;
}


void addAnywhere(PRICE one, PRICE *afterNode) {

}


void AddToEnd(PRICE one) {

}



int main() {
    printf("Введите название товара: ");
    scanf("%d", tmp.Tovar);
    printf("Введите название магазина, в котором продается товар: ");
    scanf("%d", tmp.Mag);
    printf("Введите стоимость товара в руб.");
    scanf("%d", tmp.Stoim);

}