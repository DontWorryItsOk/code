#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определение структуры Worker
struct Worker {
    char Name[100];  // Фамилия и инициалы работника
    char Pos[100];   // Название занимаемой должности
    int Year;        // Год поступления на работу
    struct Worker* next;  // указатель на следующий элемент списка
};

// Функция для добавления элемента в начало списка
struct Worker* addToBeginning(struct Worker* head, struct Worker worker) {
    struct Worker* newNode = (struct Worker*)malloc(sizeof(struct Worker));
    newNode->next = head;
    strcpy(newNode->Name, worker.Name);
    strcpy(newNode->Pos, worker.Pos);
    newNode->Year = worker.Year;
    return newNode;
}

// Функция для добавления элемента в конец списка
struct Worker* addToEnd(struct Worker* head, struct Worker worker) {
    struct Worker* newNode = (struct Worker*)malloc(sizeof(struct Worker));
    newNode->next = NULL;
    strcpy(newNode->Name, worker.Name);
    strcpy(newNode->Pos, worker.Pos);
    newNode->Year = worker.Year;

    if (head == NULL) {
        return newNode;
    }

    struct Worker* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Функция для вставки элемента в заданное место списка
struct Worker* insertAtIndex(struct Worker* head, struct Worker worker, int index) {
    struct Worker* newNode = (struct Worker*)malloc(sizeof(struct Worker));
    newNode->next = NULL;
    strcpy(newNode->Name, worker.Name);
    strcpy(newNode->Pos, worker.Pos);
    newNode->Year = worker.Year;

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Worker* current = head;
    for (int i = 0; i < index - 1 && current != NULL; ++i) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Неверный индекс для вставки.\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Функция для удаления элемента из начала списка
struct Worker* removeFromBeginning(struct Worker* head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    struct Worker* newHead = head->next;
    free(head);
    return newHead;
}

// Функция для удаления элемента из конца списка
struct Worker* removeFromEnd(struct Worker* head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Worker* current = head;
    struct Worker* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);

    if (prev != NULL) {
        prev->next = NULL;
        return head;
    } else {
        return NULL;
    }
}

// Функция для удаления элемента с заданного места списка
struct Worker* removeFromIndex(struct Worker* head, int index) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    if (index == 1) {
        struct Worker* newHead = head->next;
        free(head);
        return newHead;
    }

    struct Worker* current = head;
    struct Worker* prev = NULL;

    for (int i = 0; i < index - 1 && current != NULL; ++i) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Неверный индекс для удаления.\n");
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

// Функция для вывода списка на экран с нумерацией
void displayList(struct Worker* head) {
    printf("Список:\n");
    struct Worker* current = head;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s, %s, %d\n", index, current->Name, current->Pos, current->Year);
        current = current->next;
        index++;
    }
}

// Функция для освобождения памяти, выделенной под связанный список
void freeList(struct Worker* head) {
    struct Worker* current = head;
    while (current != NULL) {
        struct Worker* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Worker* head = NULL;
    int choice;
    struct Worker worker;

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

        // Проверка вводимого значения: 
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Введите данные работника (Фамилия_И_О, Должность, Год поступления на работу): ");
                scanf("%s %s %d", worker.Name, worker.Pos, &worker.Year);
                head = addToBeginning(head, worker);
                break;

            case 2:
                printf("Введите данные работника (Фамилия_И_О, Должность, Год поступления на работу): ");
                scanf("%s %s %d", worker.Name, worker.Pos, &worker.Year);
                head = addToEnd(head, worker);
                break;

            case 3:
                printf("Введите данные работника (Фамилия_И_О, Должность, Год поступления на работу): ");
                scanf("%s %s %d", worker.Name, worker.Pos, &worker.Year);
                int index;
                printf("Введите индекс для вставки: ");
                scanf("%d", &index);
                head = insertAtIndex(head, worker, index);
                break;

            case 4:
                head = removeFromBeginning(head);
                break;

            case 5:
                head = removeFromEnd(head);
                break;

            case 6:
                int deleteIndex;
                printf("Введите индекс для удаления: ");
                scanf("%d", &deleteIndex);
                head = removeFromIndex(head, deleteIndex);
                break;

            case 7:
                displayList(head);
                break;

            case 8:
                freeList(head);
                printf("Программа завершена.\n");
                break;

            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
        }

    } while (choice != 8);

    return 0;
}
