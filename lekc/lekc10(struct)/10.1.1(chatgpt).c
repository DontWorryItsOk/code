#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    int course;
    int group;
    char FIO[120];
    struct NODE *next;
};

struct NODE *head = NULL, *tail = NULL;

typedef struct NODE students;

void add(students one) {
    students *tmp;
    tmp = (students *)malloc(sizeof(students));
    tmp ->course = one.course;
    tmp ->group = one.group;
    strcpy(tmp ->FIO, one.FIO);
    tmp ->next = NULL;
    if(!tail) head = tmp;
    else tail ->next = tmp;
    tail = tmp;
}

students del(void) {
    students one;
    if(head != NULL) {
        one = *head;
        students *tmp;
        tmp = head;
        head = head->next;
        free(tmp);
    }
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
        printf("%s, %d из %d\n", tmp ->FIO, tmp->course, tmp->group);
        tmp = tmp->next;
    }
}

int main() {
    int m;
    students tmp;
    show();
    do {
        printf("Введите ФИО\n");
        fgets(tmp.FIO, 120, stdin);
        printf("Введите курс: \n");
        scanf("%d", &tmp.course);
        printf("Введите группу: \n");
        scanf("%d", &tmp.group);
        getchar();
        add(tmp);
        printf("Еще? 0 - нет");
        scanf("%d", &m);
        getchar();
    }
    while(m);
    show();
    tmp=del();
    printf("Первый в очереди: \n");
    printf("%s, %d из %d \n", tmp.FIO, tmp.course, tmp.group);
    return 0;
}