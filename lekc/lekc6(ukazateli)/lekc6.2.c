#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
    printf("Вы забыли указать имя");
    return 1;
    }
    printf("Привет %s", argv[1]);
    return 0;
}
