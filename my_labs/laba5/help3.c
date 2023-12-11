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
    int index = 1;

    printf("\nСписок товаров:\n");

    while (current != NULL) {
        printf("%d. Товар: %s, Магазин: %s, Стоимость: %.2f\n", index, current->Tovar, current->Mag, current->Stoim);
        current = current->next;
        index++;
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
    if (position < 1 || (position > 1 && getByNumber(position - 1) == NULL)) {
        printf("Ошибка: Указанный узел для вставки отсутствует.\n");
        return;
    }

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
        addAnywhere(newProduct, getByNumber(position - 1));
    }
}


int main() {
    int choice;
    do {
        printf("\nМеню:\n");
        printf("1. Добавить элемент в начало\n");
        printf("2. Добавить элемент в конец\n");
        printf("3. Добавить элемент в заданное место\n");
        printf("4. Удалить элемент из начала\n");
        printf("5. Удалить элемент из конца\n");
        printf("6. Удалить элемент с заданного места\n");
        printf("7. Вывести список на экран\n");
        printf("8. Выход\n");

        printf("Выберите действие (1-8): ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
            while (getchar() != '\n'); // Очистка входного буфера
            continue;
        }

        switch (choice) {
            case 1:
                push(1);
                break;

            case 2:
                push(0); // 0 для добавления в конец
                break;

            case 3:
                printf("Введите номер позиции для вставки: ");
                int position;
                if (scanf("%d", &position) != 1) {
                    printf("Ошибка ввода. Введите целое число.\n");
                    while (getchar() != '\n'); // Очистка входного буфера
                    continue;
                }
                push(position);
                break;

            case 4:
                deleteStart();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Введите номер позиции для удаления: ");
                int deletePosition;
                if (scanf("%d", &deletePosition) != 1) {
                    printf("Ошибка ввода. Введите целое число.\n");
                    while (getchar() != '\n'); // Очистка входного буфера
                    continue;
                }
                struct Price *afterNode = getByNumber(deletePosition - 1);
                if (afterNode != NULL) {
                    deleteStart();
                } else {
                    deleteEnd();
                }
                break;

            case 7:
                printList();
                break;

            case 8:
                printf("Программа завершена.\n");
                break;

            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
        }

    } while (choice != 8);

    return 0;
}
