#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int course;
    int group;
    char FIO[120];
};
struct NODE *head, *tail;
head = NULL;
tail = NULL;
typedef struct NODE students;

void add(students one) {
    students *tmp;
    tmp = (students *)malloc(sizeof(students));
    tmp ->course = one.course;
    tmp ->group = one.group;
    tmp ->FIO = one.FIO; // ошибка?
    if(!tail) head = tmp;
    else tail ->next = tmp;
    tail = tmp;
}

students del(void) {
    students one,
    one = *head;
    students *tmp;
    tmp = head;
    head = head->next;
    free(tmp);
    return one;
}

void show(void) {
    students *tmp = head;
    printf("Содержимое очереди: \n");
    if(tmp == NULL) {
        printf("Очередь пуста\n");
        return;
    }
    while(tmp) {
        printf("%S, %d из %d\n", tmp ->FIO, tmp->course, tmp->group);
    }
}

int main() {
    students tmp;
    show();
    do {
        printf("Введите ФИО\n");
        gets(tmp.FIO);
        printf("Введите курс: \n");
        scanf("%d ", &tmp.course);
        printf("Введите группу: \n");
        scanf("%d", &tmp.group);
        add(tmp);
        printf("Еще? 0 - нет");
        scanf("%d", &m); // откуда m????
    }
    while(m);
    show();
    tmp=del();
    printf("Первый в очереди: \n");
    printf("%S, %d из %d \n", tmp.FIO, tmp.course, tmp.group);
    return 0;
}
