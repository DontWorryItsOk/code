#include <stdio.h>
int main() {
    int arr [1000];
    int N;
    int i;
    printf("Введите количество элементов: ");
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        printf("Введите %d-й элемент: ", i);
        scanf("%d", &arr[i]);
    }
    return 0;
}