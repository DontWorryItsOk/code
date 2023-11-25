#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char str[80];
    if(argc != 2) {
        printf("Некорректное использование");
        exit(1);
    }
    printf(stdout, "Вы хотите удалить файл %s ([Y]/[N])?", argv[1]);
    gets(str);
    if(toupper(*str) == 'y') {
        if(remove(argv[1])) {
            printf("Невозможно удалить файл");
            exit(1);
        }
    }
    return 0;
}

// в exe ввести путь к файлу для работы программы