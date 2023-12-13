#include <stdio.h>
#include <stdlib.h>
#include <string.h> // для strcpy

struct Price {
    char Tovar[50];
    char Mag[50];
    int Stoim;
    struct Price *next; // указатель на следующий элемент списка
};

struct Node {
    struct Price info;
    struct Node *next;
};

typedef struct Price PRICE;
typedef struct Node NODE;


NODE *add_to_start(NODE *head, PRICE newtowar) {
    NODE *tmp = (NODE *)malloc(sizeof(PRICE));
    tmp -> info = newtowar;
    tmp -> next = head;
    return tmp;
}


NODE *add_to_end(NODE *head, PRICE newtowar) {
    NODE *tmp = (NODE *)malloc(sizeof(PRICE));
    tmp -> info = newtowar;
    tmp -> next = NULL;

    if (head == NULL) {
        return tmp;
    }

    NODE *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = tmp;
    return head;
}


NODE *add_anywhere(NODE *head, PRICE newtowar, int index) {
    NODE *tmp = (NODE *)malloc(sizeof(PRICE));
    tmp->info = newtowar;
    tmp->next = NULL;

    if (index == 0) {
    tmp->next = head;
    return tmp;
    }

    NODE *current = head;
    for (int i = 0; i < index - 1 && current != NULL; ++i) {
    current = current->next;
    }

    if (current == NULL) {
        printf("Неверный индекс для вставки.\n");
        free(tmp);
        return head;
    }

    tmp->next = current->next;
    current->next = tmp;
    return head;
}



NODE *delete_from_start(NODE *head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    struct Node* newHead = head->next;
    free(head);
    return newHead;
}


NODE *delete_from_end(NODE *head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    NODE *current = head;
    NODE *prev = NULL;

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


NODE *delete_anywhere(NODE *head, int index) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return NULL;
    }

    if (index == 1) {
        struct Node* newHead = head->next;
        free(head);
        return newHead;
    }

    NODE *current = head;
    NODE *prev = NULL;

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


void show(NODE *head) {
    printf("Список:\n");
    NODE *current = head;
    int index = 1; // FFF
    while (current != NULL) {
        printf("%d. %s, %s, %d\n", index, current->info.Tovar, current->info.Mag, current->info.Stoim);
        current = current->next;
        index++;
    }
}


void free_memory(NODE *head) {
    NODE *current = head;
    while (current != NULL) {
        NODE *temp = current;
        current = current->next;
        free(temp);
    }
}


// Вывод информации о товаре по его названию
void search_tovar(NODE *head, const char *name) {
    NODE *current = head;
    while (current != NULL) {
        if (strcmp(current->info.Tovar, name) == 0) {
            printf("Информация о товаре:\nНазвание: %s\nМагазин: %s\nЦена: %d\n", current->info.Tovar, current->info.Mag, current->info.Stoim);
            return;
        }
        current = current->next;
    }

    printf("Товар с названием '%s' не найден.\n", name);
}


int main() {
    NODE *head = NULL;
    int answer;
    PRICE newtowar;

    do {
        printf("\nМеню:\n");
        printf("1. Добавить элемент в начало списка\n");
        printf("2. Добавить элемент в конец списка\n");
        printf("3. Добавить элемент в выбранное место в списке\n");
        printf("4. Удалить элемент из начала списка\n");
        printf("5. Удалить элемент из конца списка\n");
        printf("6. Удалить элемент с выбранного места в списке\n");
        printf("7. Вывести список\n");
        printf("8. Вывести информацию о товаре по названию\n");
        printf("9. Выход\n");

        printf("Выберите действие (1-9): ");

        // Проверка вводимого значения: 
        if (scanf("%d", &answer) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
            while (getchar() != '\n'); // Очистка входного буфера
            continue;
        }

        switch (answer) {
            case 1:
                printf("Введите данные товара (Название, Магазин и Стоимость): ");
                scanf("%s %s %d", newtowar.Tovar, newtowar.Mag, &newtowar.Stoim);
                head = add_to_start(head, newtowar);
                break;

            case 2:
                printf("Введите данные товара (Название, Магазин и Стоимость): ");
                scanf("%s %s %d", newtowar.Tovar, newtowar.Mag, &newtowar.Stoim);
                head = add_to_end(head, newtowar);
                break;

            case 3:
                printf("Введите данные товара (Название, Магазин и Стоимость): ");
                scanf("%s %s %d", newtowar.Tovar, newtowar.Mag, &newtowar.Stoim);
                int index;
                printf("Введите индекс для вставки: ");
                scanf("%d", &index);
                head = add_anywhere(head, newtowar, index);
                break;

            case 4:
                head = delete_from_start(head);
                break;

            case 5:
                head = delete_from_end(head);
                break;

            case 6:
                int deleteIndex;
                printf("Введите индекс для удаления: ");
                scanf("%d", &deleteIndex);
                head = delete_anywhere(head, deleteIndex);
                break;

            case 7:
                show(head);
                break;

            case 8:
                char search[50];
                printf("Введите название товара: ");
                scanf("%s", search);
                search_tovar(head, search);
                break;

            case 9:
                free_memory(head);
                printf("Программа завершена.\n");
                break;

            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
        }

    } while (answer != 9);

    return 0;
}

// решил проблему с бесконечным выполнением программы в случае введения буквы
// добавить возможность вводить ФИО через пробелы?
// при вводе d d d выводит ошибку ввода, но в список добавляет
// индекс на 1 больше чем надо(при вводе 3 вставляет после 3)
// проблемы с освобождением памяти