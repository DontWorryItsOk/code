#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Price {
    char Tovar[50];
    char Mag[50];
    float Stoim;
    struct Price *next;
};

struct Price *head = NULL;
struct Price *tail = NULL;

void addStart(struct Price data) {
    struct Price *newNode = (struct Price *)malloc(sizeof(struct Price));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->Tovar, data.Tovar);
    strcpy(newNode->Mag, data.Mag);
    newNode->Stoim = data.Stoim;
    newNode->next = head;
    head = newNode;

    if (tail == NULL) {
        tail = newNode;
    }
}

void addEnd(struct Price data) {
    struct Price *newNode = (struct Price *)malloc(sizeof(struct Price));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }

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

void addAnywhere(struct Price data, struct Price *afterNode) {
    if (afterNode == NULL) {
        printf("Ошибка: Указанный узел для вставки отсутствует.\n");
        return;
    }

    struct Price *newNode = (struct Price *)malloc(sizeof(struct Price));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->Tovar, data.Tovar);
    strcpy(newNode->Mag, data.Mag);
    newNode->Stoim = data.Stoim;
    newNode->next = afterNode->next;
    afterNode->next = newNode;

    if (afterNode == tail) {
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

struct Price *getByNumber(int number) {
    struct Price *current = head;
    int count = 1;

    while (current != NULL && count < number) {
        current = current->next;
        count++;
    }

    return current;
}

void push(int position) {
    struct Price newProduct;
    printf("Введите название товара: ");
    scanf("%s", newProduct.Tovar);

    printf("Введите название магазина: ");
    scanf("%s", newProduct.Mag);

    printf("Введите стоимость товара: ");
    if (scanf("%f", &newProduct.Stoim) != 1) {
        printf("Ошибка ввода стоимости.\n");
        return;
    }

    if (position == 1) {
        addStart(newProduct);
    } else {
        struct Price *afterNode = getByNumber(position - 1);
        if (afterNode == NULL) {
            printf("Ошибка: Указанный узел для вставки отсутствует.\n");
            return;
        }

        addAnywhere(newProduct, afterNode);
    }
}



int main() {
    int value;
    do {
        printf("Введите номер позиции для вставки (0 - завершить): ");
        scanf("%d", &value);
        if (value == 0) break;
        push(value);
    } while (1);

    printf("\nСписок товаров:\n");
    printList();

    return 0;
}
