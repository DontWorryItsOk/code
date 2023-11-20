#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *fp;
    char str[80];
    int r;
   
    if ((fp=fopen("test", "wb")) == NULL); {
        printf("Невозм. открыть файл");
        exit(1);
    }
    
    printf("Введите строку и целое число");
    fscanf(stdin, "%s%d", str, &r);
    fprintf(fp, "%s %d", str, r);
    fclose(fp);

    if ((fp=fopen("test", "r")) == NULL) {
        printf("Невозм. открыть файл");
        exit(1);
    }

    fscanf(fp, "%s%s", str, &r);
    
    // имя массива является указателем на массив
    
    fprintf(stdout, "строка: %s\n число:%d", str, r);
    fclose(fp);
    return 0;
}