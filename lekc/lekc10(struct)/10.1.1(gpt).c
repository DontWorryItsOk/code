#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    int course;
    int group;
    char FIO[120];
    struct NODE *next; // Added next pointer
};

typedef struct NODE students;

struct NODE *head = NULL;
struct NODE *tail = NULL;

void add(students one) {
    students *tmp;
    tmp = (students *)malloc(sizeof(students));
    tmp->course = one.course;
    tmp->group = one.group;
    strcpy(tmp->FIO, one.FIO);
    tmp->next = NULL; // Initialize next pointer
    if (!tail) {
        head = tmp;
    } else {
        tail->next = tmp;
    }
    tail = tmp;
}

students del(void) {
    students one;
    students *tmp;
    if (!head) {
        printf("Очередь пуста\n");
        return one;
    }
    tmp = head;
    head = head->next;
    free(tmp);
    return one;
}

void show(void) {
    students *tmp = head;
    printf("Содержимое очереди:\n");
    if (tmp == NULL) {
        printf("Очередь пуста.\n");
        return;
    }
    while (tmp) {
        printf("%s, %d из %d\n", tmp->FIO, tmp->course, tmp->group);
        tmp = tmp->next;
    }
}

int main() {
    int m;
    students tmp;
    show();
    do {
        printf("Введите ФИО\n");
        getchar(); // Consume the newline character from the previous input
        fgets(tmp.FIO, sizeof(tmp.FIO), stdin);
        printf("Введите курс: \n");
        scanf("%d", &tmp.course);
        printf("Введите группу: \n");
        scanf("%d", &tmp.group);
        add(tmp);
        printf("Еще? 0 - нет");
        scanf("%d", &m);
    } while (m);
    show();
    tmp = del();
    printf("Первый в очереди: \n");
    printf("%s, %d из %d \n", tmp.FIO, tmp.course, tmp.group);
    return 0;
}
