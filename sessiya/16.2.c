/* 16.	Разработайте и реализуйте программу, 
которая находит длину самого длинного слова в предложении, 
вводимом пользователем.*/

#include <stdio.h>
#include <string.h>

int main() {
    char arr[1000];
    printf("Введите текст: ");
    scanf("%[^\n]", arr);

    printf("Введеный вами текст: %s", arr);

    int N = strlen(arr);

    int length = 0, max_length = 0, i = 0;
    for(int i = 0; i < N; i++) { 
        if(arr[i] != ' ') {
            length++;
        }

        if(arr[i] == ' ') {
            if(length > max_length) {
                max_length = length;
            }
            length = 0;
        }
    }

    if(length > max_length) { // потому что последнее слово не успевает провериться
        max_length = length;
    }
    
    printf("\nДлина самого длинного слова равна %d", max_length);
    return 0;
}