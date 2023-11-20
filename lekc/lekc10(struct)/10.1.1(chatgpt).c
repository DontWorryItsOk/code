#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    int course;
    int group;
    char FIO[120];
    struct NODE *next;
};
struct NODE *head = NULL;
struct NODE *tail = NULL;

typedef struct NODE students;

void add(students one) {
    students *tmp;
    tmp = (students *)malloc(sizeof(students));
    if (tmp == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    tmp->course = one.course;
    tmp->group = one.group;
    strcpy(tmp->FIO, one.FIO);
    tmp->next = NULL;
    if (!tail) {
        head = tmp;
    } else {
        tail->next = tmp;
    }
    tail = tmp;
}

students del(void) {
    if (!head) {
        fprintf(stderr, "Очередь пуста\n");
        exit(EXIT_FAILURE);
    }
    students one = *head;
    students *tmp = head;
    head = head->next;
    free(tmp);
    return one;
}

void show(void) {
    students *tmp = head;
    printf("Содержимое очереди: \n");
    if (tmp == NULL) {
        printf("Очередь пуста\n");
        return;
    }
    
    int position = 1;  // Добавим переменную для отслеживания позиции в очереди
    
    while (tmp) {
        printf("%s, %d из %d\n", tmp->FIO, position, tmp->group);
        tmp = tmp->next;
        position++;
    }
}


int main() {
    int m;
    students tmp;
    show();
    do {
        printf("Введите ФИО\n");
        fgets(tmp.FIO, sizeof(tmp.FIO), stdin);
        tmp.FIO[strcspn(tmp.FIO, "\n")] = '\0';  // Убираем символ новой строки

        do {
            printf("Введите курс (не ноль): \n");
            if (scanf("%d", &tmp.course) != 1) {
                printf("Ошибка ввода! Пожалуйста, введите число.\n");
                while (getchar() != '\n');  // Очистка буфера ввода
                continue;
            }
        } while (tmp.course == 0);

        do {
            printf("Введите группу (не ноль): \n");
            if (scanf("%d", &tmp.group) != 1) {
                printf("Ошибка ввода! Пожалуйста, введите число.\n");
                while (getchar() != '\n');  // Очистка буфера ввода
                continue;
            }
        } while (tmp.group == 0);

        add(tmp);
        printf("Еще? 0 - нет ");
        scanf(" %d", &m);
        while (getchar() != '\n'); // Очистка буфера ввода
    } while (m);
    show();
    tmp = del();
    printf("Первый в очереди: \n");
    printf("%s, %d из %d \n", tmp.FIO, tmp.course, tmp.group);

    // Освободим память, выделенную для списка
    students *current = head;
    while (current) {
        students *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
