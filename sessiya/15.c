/* 15.	Разработайте функцию, возвращающую True, если число является палиндромом
(его запись читается одинаково справа-налево и слева-направо) 
и False в противном случае.*/

#include <stdio.h>
#include <string.h>

int func(char arr[]) {
    int N = strlen(arr);
    int test = 1;
    for(int i = 0; i < N/2; i++) {
        if(arr[i] != arr[N-i-1]) {
            test = 0;
            return 0;
        }
    }

    if(test == 1) {
        return 1;
    }
}


int main() {
    char arr[1000];
    printf("Введите число: ");
    scanf("%[^\n]", arr);

    printf("Ваше число: %s", arr);
    if(func(arr)) {
        printf("\nЭто число является палиндромом");
    }
    else printf("\nЭто число не является палиндромом");
    return 0;
}