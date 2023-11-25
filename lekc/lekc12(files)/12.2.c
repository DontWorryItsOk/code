#include <stdio.h>

int main() {
    char str[80];
    freopen("output", "w", stdout);
    printf("Введите строку: ");
    gets(str);
    printf("%s", str);
    return 0;
}