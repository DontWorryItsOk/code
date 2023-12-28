#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Определение структуры Worker. Хранит информацию о работнике
struct Worker {
    char Name[100];     // Фамилия и инициалы работника
    char Pos[100];     // Название занимаемой должности
    int Year;         // Год поступления на работу
};

// Определение структуры Node для связанного списка
struct Node {
    struct Worker data; //Содержит данные работника представленные структурой Worker.
    struct Node* next; // Указатель на следующий элемент связанного списка
};

// Функция для создания нового работника
struct Worker createWorker() {
    struct Worker worker;
    return worker;
}



// Функция для удаления символа новой строки из строки, используем ее потому, что scanf оставляет символ новой строки во входном буфере
void removeNewline(char* str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';  // Заменяем символ новой строки на нулевой символ
    }
}

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

    if (head == NULL) { // Проверка наличия головы списка
        return newNode;
    }

    struct Node* current = head; // Перебор списка до псоледнего узла
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Функция для вставки элемента в заданное место списка
struct Node* insertAtIndex(struct Node* head, struct Worker worker, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Выделяем тут память
    newNode->data = worker;
    newNode->next = NULL;

    if (index == 1) { // Проверка, является ли вставка в начало списка
        newNode->next = head;
        return newNode;
    }

// Если вставка не в начало, выполняется перебор списка
    struct Node* current = head;
    struct Node* prev = NULL;

    for (int i = 0; i < index - 1 && current != NULL; i++) { // Перебираем узлы списка до указанного индекса или до конца списка
        prev = current;
        current = current->next;
    }

    if (current == NULL || index <= 0) {
        printf("Неверный индекс для вставки.\n");
        free(newNode);
        return head;
    }

    newNode->next = current;
    if (prev != NULL) {         // Проверяет, есть ли у нас предыдущий узел что означает, что мы не вставляем новый узел в начало списка.
        prev->next = newNode;  // Если есть предыдущий узел, то устанавливаем указатель next предыдущего узла так, чтобы он указывал на новый узел
        return head;          // Если узел вставляется не в начало
    } 
    else {
       return newNode;  
    }
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

    if (head->next == NULL) { // Проверка на единственный элемент
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
    } 
    else {
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

    for (int i = 0; i < index - 1 && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL || index <= 0) {
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

// Функция для вывода фамилий работников со стажем больше заданного
void printWorkersWithExperience(struct Node* head, int currentYear) {
    struct Node* current = head;

    printf("Работники со стажем более (в годах): ");
    int minExperience;
    scanf("%d", &minExperience);

    printf("Работники со стажем более %d лет:\n", minExperience);

    while (current != NULL) {
        int experience = currentYear - current->data.Year;
        if (experience > minExperience) {
            printf("%s (Стаж: %d лет)\n", current->data.Name, experience);
        }
        current = current->next;
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
        printf("8. Вывести работников со стажем больше заданного\n");
        printf("9. Выход\n");
        

        printf("Выберите действие (1-9): ");

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
                int currentYear;
                printf("Введите текущий год: ");
                scanf("%d", &currentYear);
                printWorkersWithExperience(head, currentYear);
                break;

            case 9:
                freeList(head);
                printf("Программа завершена.\n");
                break;

            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
        }

    } while (choice != 9);

    return 0;
}
