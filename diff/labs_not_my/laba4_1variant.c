#include <stdio.h>

void calculate_scores(int n, int numbers[100]) {
    int player1_score = 0;
    int player2_score = 0;

    while (n > 0) {
        if (n == 1) {
            player1_score += numbers[0];
            break;
        } else if (numbers[0] == numbers[n-1]) {
            player1_score += numbers[0];
            n--;
        } else {
            int max_number = (numbers[0] > numbers[n-1]) ? numbers[0] : numbers[n-1];
            player1_score += max_number;
            if (max_number == numbers[0]) {
                for (int i = 0; i < n-1; i++) {
                    numbers[i] = numbers[i+1];
                }
            } else {
                n--;
            }
        }

        if (n == 0) {
            break;
        }

        int max_number = (numbers[0] > numbers[n-1]) ? numbers[0] : numbers[n-1];
        player2_score += max_number;
        if (max_number == numbers[0]) {
            for (int i = 0; i < n-1; i++) {
                numbers[i] = numbers[i+1];
            }
        } else {
            n--;
        }
    }

    printf("Очки игрока 1: %d\n", player1_score);
    printf("Очки игрока 2: %d\n", player2_score);
}

int main() {
    int numbers[100];
    int n;
    int i = 1, j = 0;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    for (int k = 0; k < n; k++) {
        printf("Введите %d-й элемент массива: ", i);
        scanf("%d", &numbers[k]);
        i++;
    }

    calculate_scores(n, numbers);

    return 0;
}