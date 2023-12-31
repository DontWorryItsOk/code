#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определение структуры Worker
struct Worker {
    char Name[100];  // Фамилия и инициалы работника
    char Pos[100];   // Название занимаемой должности
    int Year;        // Год поступления на работу
};

// Определение структуры Node для связанного списка
struct Node {
    struct Worker data;
    struct Node* next;
};

// Функция для добавления элемента в начало списка
struct Node* addToBeginning(struct Node* head, struct Worker worker) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = worker;
    newNode->next = head;
    return newNode;
}

// Функция для добавления элемента в конец списка
struct Node* addToEnd(struct Node* head, struct Worker worker) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = worker;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Функция для вставки элемента в заданное место списка
struct Node* insertAtIndex(struct Node* head, struct Worker worker, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = worker;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
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
struct Node* removeFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    struct Node* newHead = head->next;
    free(head);
    return newHead;
}

// Функция для удаления элемента из конца списка
struct Node* removeFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);

    if (prev != NULL) {
        prev->next = NULL;
        return head;
    } else {
        return NULL;  // В случае удаления единственного элемента в списке
    }
}

// Функция для удаления элемента с заданного места списка
struct Node* removeFromIndex(struct Node* head, int index) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    if (index == 1) {
        struct Node* newHead = head->next;
        free(head);
        return newHead;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

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
void displayList(struct Node* head) {
    printf("Список:\n");
    struct Node* current = head;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s, %s, %d\n", index, current->data.Name, current->data.Pos, current->data.Year);
        current = current->next;
        index++;
    }
}

// Функция для освобождения памяти, выделенной под связанный список
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
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
            while (getchar() != '\n'); // Очистка входного буфера
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

// решил проблему с бесконечным выполнением программы в случае введения буквы
// добавить возможность вводить ФИО через пробелы?