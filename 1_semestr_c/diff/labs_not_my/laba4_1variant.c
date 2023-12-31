#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void calculateScore(int arr[100], int n, int playerScores[2]) {
    int left = 0, right = n - 1;

    playerScores[0] = 0;
    playerScores[1] = 0;

    int currentPlayer = 1;

    while (left <= right) {
        if (arr[left] == arr[right]) {
            playerScores[currentPlayer - 1] += arr[left];
            left++;
        } else if (arr[left] > arr[right]) {
            playerScores[currentPlayer - 1] += arr[left];
            left++;
        } else {
            playerScores[currentPlayer - 1] += arr[right];
            right--;
        }

        currentPlayer = 3 - currentPlayer;
    }
}

int main() {
    int n, i = 1;
    int arr[100];
    
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    for (int k = 0; k < n; k++) {
        printf("Введите %d-й элемент массива: ", i);
        scanf("%d", &arr[k]);
        i++;
    }


    int playerScores[2];
    calculateScore(arr, n, playerScores);

    printf("Игрок 1: %d очков\n", playerScores[0]);
    printf("Игрок 2: %d очков\n", playerScores[1]);

    return 0;
}
