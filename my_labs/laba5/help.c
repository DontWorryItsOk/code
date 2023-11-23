#include <stdio.h>
#include <stdlib.h>
#include <string.h> // для strcpy

struct Price {
    char Tovar[50];
    char Mag[50];
    float Stoim;
    struct Price *next;  // указатель на следующий элемент списка
};

struct Price *head = NULL;
struct Price *tail = NULL;

void addStart(struct Price data) {
    struct Price *newNode = (struct Price *)malloc(sizeof(struct Price));
    strcpy(newNode->Tovar, data.Tovar);
    strcpy(newNode->Mag, data.Mag);
    newNode->Stoim = data.Stoim;
    newNode->next = head;
    head = newNode;

    if (tail == NULL) {
        tail = newNode;
    }
}

void addAnywhere(struct Price data, struct Price *afterNode) {
    if (afterNode == NULL) {
        printf("Ошибка: Указанный узел для вставки отсутствует.\n");
        return;
    }

    struct Price *newNode = (struct Price *)malloc(sizeof(struct Price));
    strcpy(newNode->Tovar, data.Tovar);
    strcpy(newNode->Mag, data.Mag);
    newNode->Stoim = data.Stoim;
    newNode->next = afterNode->next;
    afterNode->next = newNode;
    
    // Если afterNode - последний элемент, обновим tail
    if (afterNode == tail) {
        tail = newNode;
    }
}

void addEnd(struct Price data) {
    struct Price *newNode = (struct Price *)malloc(sizeof(struct Price));
    strcpy(newNode->Tovar, data.Tovar);
    strcpy(newNode->Mag, data.Mag);
    newNode->Stoim = data.Stoim;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


void deleteStart() {
    if (head == NULL) {
        printf("Список пуст.\n");
        return;
    }

    struct Price *temp = head;
    head = head->next;

    free(temp);
    if (head == NULL) {
        tail = NULL;
    }
}

void deleteEnd() {
    if (head == NULL) {
        printf("Список пуст.\n");
        return;
    }

    struct Price *temp = head;
    struct Price *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
        tail = prev;
    } else {
        head = tail = NULL;
    }

    free(temp);
}

void printList() {
    struct Price *current = head;

    while (current != NULL) {
        printf("Товар: %s, Магазин: %s, Стоимость: %.2f\n", current->Tovar, current->Mag, current->Stoim);
        current = current->next;
    }
}

struct Price* getByNumber(int number) {
    struct Price *current = head;
    int count = 1;

    while (current != NULL && count < number) {
        current = current->next;
        count++;
    }

    return current;
}

int main() {
    struct Price newProduct;
    int value;
    do {
        printf("Введите название товара: ");
        scanf("%s", newProduct.Tovar);

        printf("Введите название магазина: ");
        scanf("%s", newProduct.Mag);

        printf("Введите стоимость товара: ");
        scanf("%f", &newProduct.Stoim);

        addEnd(newProduct);

        printf("Введите элемент, 0 - конец\n");
        scanf("%d", &value);
        if(!value) break;
        push(value); // тут не push
    }
    while(1);

        printf("\nСписок товаров:\n");
        printList();

    return 0;
}