#include <stdio.h>
#include <ctype.h>
void print_upper(char string[]) {
    int t;
    for(t=0; string[t] != 0; t++) {
        string[t] = toupper(string[t]); // ф-ция toupper принимает символ
        printf("%c", string[t]);
    }
}

int main() {
    char S[80];
    gets(S);
    print_upper(S);
    printf("\nСтрока: %c", S); // %c выводит строку
    return 0;
}
